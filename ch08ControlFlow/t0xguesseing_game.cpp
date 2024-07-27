#include <cstdint>
#include <cstdlib>
#include <chrono>
#include <random>
#include <iostream>

namespace {
    constexpr uint16_t min              {   1 };
    constexpr uint16_t max              { 100 };
    constexpr uint16_t numGuesses       {  10 };

    inline namespace RandomInit {
        std::random_device rd{};
        std::seed_seq ss {
            static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count(),
                    rd(), rd(), rd(), rd(), rd(), rd(), rd()) };
        std::mt19937 mt{ std::mt19937{ ss } };
    }
}

bool playAgain();
bool HiLoGame(uint16_t guesses, uint16_t min, uint16_t max);

int main() {
    do {
        HiLoGame(numGuesses, min, max);
    } while (playAgain());
    return EXIT_SUCCESS;
}

bool playAgain() {
    for (;;) {
        char ch{};
        std::cout<<"Would you like to play again (y/n)? ";
        std::cin>>ch;
        switch (ch) {
        case 'y':
            return true;
        case 'n':
            return false;
        }
    }
}

bool HiLoGame(uint16_t guesses, uint16_t min, uint16_t max) {
    std::cout
        <<"Let's play a game. I'm thinking of a number between "
        <<min<<" and "<<max<< ". You have "
        <<guesses<<" tries to guess what it is.\n";
    uint16_t secretNum{ std::uniform_int_distribution{min, max}(mt) };
    for (uint16_t count{1}; count<=guesses; ++count) {
        std::cout<<"Guess #"<<count<<": ";
        uint16_t guess{};
        std::cin>>guess;
        if (guess==secretNum) {
            std::cout<<"Correct! You win!\n";
            return true;
        } else if (guess>secretNum)
            std::cout<<"Your guess is too high.\n";
        else
            std::cout<<"Your guess is too low.\n";
    }
    std::cout<<"Sorry, you lose. The correct number was "<<secretNum<<'\n';
	return false;
}
