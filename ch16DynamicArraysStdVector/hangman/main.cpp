#include <cstdlib>
#include <cstdint>
#include <cctype>
#include <limits>
#include <string_view>
#include <vector>
#include <iostream>

#define RANDOM_HIDDEN_WORD

#ifdef RANDOM_HIDDEN_WORD
#include "randgen.hpp"
namespace WordList {
    std::vector<std::string_view> words { "mystery", "broccoli", "account",
                                          "almost", "spaghetti", "opinion",
                                          "beautiful", "distance", "luggage" };
    std::string_view getRandomWord() {
        return words[Randgen::get<uint32_t>(0, words.size()-1)];
    }
}
#endif

namespace Settings {
    constexpr uint8_t avilableWrongGuesses{ 6 };
}

class Session {
#ifdef RANDOM_HIDDEN_WORD
    const std::string_view hiddenWord{ WordList::getRandomWord() };
#else
    static constexpr std::string_view hiddenWord{ "hello" };
#endif
    uint8_t wrongGuessesLeft{Settings::avilableWrongGuesses};
    std::vector<bool> guessedLetters{ std::vector<bool>('z'-'a'+1, false) };

    constexpr bool isLetterGuessed(char letter) const {
        return guessedLetters[static_cast<uint8_t>(std::tolower(letter)-'a')];
    }

    constexpr void setLetterGuessed(char letter) {
        guessedLetters[static_cast<uint8_t>(std::tolower(letter)-'a')] = true;
    }

    bool isLetterInWord(char letter) const {
        for (char wLetter : hiddenWord)
            if (letter == wLetter)
                return true;
        return false;
    }
public:

    void printInfo() const {
        std::cout << "The word: ";
        for (char letter : hiddenWord)
            std::cout << (isLetterGuessed(letter)? letter : '_');
        std::cout << "\tWrong guesses: ";
        for (uint8_t count{0}; count < wrongGuessesLeft; ++count)
            std::cout << '+';
        for (char letter{'a'}; letter<='z'; ++letter)
            if (isLetterGuessed(letter) && !isLetterInWord(letter))
                std::cout << letter;
        std::cout << '\n';
    }

    bool handleGuess(char letter) {
        if (letter < 'a' || letter > 'z') {
            std::cout << "That wasn't a valid input.  Try again.\n";
            return false;
        }
        if (isLetterGuessed(letter)) {
            std::cout << "You already guessed that.  Try again.\n";
            return false;
        }
        setLetterGuessed(letter);
        if (isLetterInWord(letter)) {
            std::cout << "Yes, '" << letter << "' is in the word!\n";
            return true;
        }
        std::cout << "No, '" << letter << "' is not in the word!\n";
        --wrongGuessesLeft;
        return true;
    }

    enum class WinState {
        continuation,
        victory,
        defeat,
    };

    WinState isWon() const {
        if (wrongGuessesLeft == 0) {
            std::cout << "You lost! The word was: " << hiddenWord << '\n';
            return WinState::defeat;
        }
        for (char letter : hiddenWord)
            if (!isLetterGuessed(letter))
                return WinState::continuation;
        std::cout << "You win! The word was: " << hiddenWord << '\n';
        return WinState::victory;
    }
};

char getGuess() {
    while (true) {
        std::cout << "Enter you next letter: ";
        char c{};
        std::cin >> c;
        if (!std::cin) {
            std::cin.clear();
            std::cout << "That wasn't a valid input.  Try again.\n";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return c;
    }
}

int main() {
    Session s{};
    while (s.isWon() == Session::WinState::continuation) {
        s.printInfo();
        while (!s.handleGuess(getGuess())) ;
    }
    return EXIT_SUCCESS;
}
