#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <chrono>
#include <random>
#include <array>
#include <algorithm>
#include <iostream>

namespace Randgen {
    std::mt19937 helpInitMt() {
        std::random_device rd{};
        std::seed_seq seedSeq{
            static_cast<std::seed_seq::result_type>(
                    std::chrono::steady_clock::now().time_since_epoch().count(),
                    rd(), rd(), rd(), rd(), rd(), rd(), rd() )
        };
        return std::mt19937{ seedSeq };
    }

    std::mt19937 state{ helpInitMt() };

    template <typename T>
    T get(const T& min, const T& max) {
        return std::uniform_int_distribution<T>( min, max )(state);
    }
};

struct Card {
    enum class Rank {
        ace, two, three, four,
        five, six, seven,
        eight, nine, ten,
        jack, queen, king,

        max_rank
    };
    enum class Suit {
        club, diamond, heart, spade,

        max_suits
    };
    using enum Rank;
    static constexpr std::array allRanks {
        ace, two, three, four,
        five, six, seven,
        eight, nine, ten,
        jack, queen, king,
    };
    using enum Suit;
    static constexpr std::array allSuits {
        club, diamond, heart, spade,
    };
    Rank rank{};
    Suit suit{};
    friend std::ostream& operator<<(std::ostream& out, const Card& card) {
        static constexpr std::array ranks {
            'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'
        };
        static constexpr std::array suits {
            'C', 'D', 'H', 'S'
        };
        return out << ranks[static_cast<uint32_t>(card.rank)]
            << suits[static_cast<uint32_t>(card.suit)];
    }
    uint32_t value() const {
        if (rank == ace)
            return 11;
        else if (rank < ten)
            return static_cast<uint32_t>(rank)+1;
        else
            return 10;
    }
};

class Deck {
    std::array<Card, 52> cards{};
    std::size_t nextCardIndex{0};
public:
    Deck() {
        std::size_t count{ 0 };
        for (auto suit : Card::allSuits)
            for (auto rank : Card::allRanks)
                cards[count++] = Card{rank, suit};
    }
    void shuffle() {
        std::shuffle(cards.begin(), cards.end(), Randgen::state);
        nextCardIndex = 0;
    }
    Card dealCard() {
        assert(nextCardIndex != 52 && "Deck::dealCard run out of cards");
        return cards[nextCardIndex++];
    }
};

class Player {
    uint32_t score_{};
    uint32_t aceCount{ 0 };
public:
    void addToScore(Card card) {
        score_ += card.value();
        if (card.rank == Card::ace)
            ++aceCount;
    }
    void consumeAces(uint32_t maxScore) {
        while (score_ > maxScore && aceCount > 0) {
            score_ -= 10;
            --aceCount;
        }
    }
    uint32_t score() const {
        return score_;
    }
};

namespace Settings {
    constexpr uint32_t bust{ 21 };
    constexpr uint32_t dealerStopAt{ 17 };
};

bool playerWantsHit() {
    while (true) {
        std::cout << "(h) to hit, or (s) to stand: ";
        char ch{};
        std::cin >> ch;
        switch (ch) {
        case 'h':
            return true;
        case 's':
            return false;
        }
    }
}

bool playerTurn(Deck &deck, Player player) {
    while (player.score() < Settings::bust && playerWantsHit()) {
        Card card { deck.dealCard() };
        player.addToScore(card);
        player.consumeAces(Settings::bust);
        std::cout << "You werw dealt " << card << ". You now have: "
            << player.score() << '\n';
    }
    if (player.score() > Settings::bust) {
        std::cout << "You went bust!\n";
        return true;
    }
    return false;
}

bool dealerTurn(Deck& deck, Player& dealer) {
    while (dealer.score() < Settings::dealerStopAt) {
        Card card { deck.dealCard() };
        dealer.addToScore(card);
        dealer.consumeAces(Settings::bust);
        std::cout << "The dealer flips a " << card
            << ". They now have: " << dealer.score() << '\n';
    }
    if (dealer.score() > Settings::bust) {
        std::cout << "The dealer went bust!\n";
        return true;
    }
    return false;
}

enum class GameResult {
    playerWon,
    dealerWon,
    tie
};

GameResult playBlackjack() {
    Deck deck{};
    deck.shuffle();
    Player dealer{};
    Card card1{ deck.dealCard() };
    dealer.addToScore(card1);
    std::cout << "The dealer is showing: " << card1
        << " (" << dealer.score() << ")\n";
    Player player {};
    Card card2{ deck.dealCard() };
    Card card3{ deck.dealCard() };
    player.addToScore(card2);
    player.addToScore(card3);
    std::cout << "You are showing " << card2 << ' '
        << card3 << " (" << player.score() << ")\n";
    if (playerTurn(deck, player))
        return GameResult::dealerWon;
    if (dealerTurn(deck, dealer))
        return GameResult::playerWon;
    if (player.score() == dealer.score())
        return GameResult::tie;
    return player.score() > dealer.score() ? GameResult::playerWon :
        GameResult::dealerWon;
}

int main() {
    switch (playBlackjack()) {
    case GameResult::playerWon:
        std::cout << "You win!\n";
        break;
    case GameResult::dealerWon:
        std::cout << "You lose!\n";
        break;
    case GameResult::tie:
        std::cout << "It's a tie.\n";
        break;
    }
    return EXIT_SUCCESS;
}
