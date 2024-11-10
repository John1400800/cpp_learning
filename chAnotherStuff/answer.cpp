#include <cstdlib>
#include <cstdint>
#include <cctype>
#include <limits>
#include <string_view>
#include <iostream>

bool askYesNo(std::string_view question);

int main(int32_t, const char**) {
    bool answer{ askYesNo("just answer") };
    std::cout << std::boolalpha << answer <<'\n';
    return EXIT_SUCCESS;
}

bool askYesNo(std::string_view question) {
    std::string answer;
    while (true) {
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        std::cout << question << " (y/n): ";
        std::cin >> answer;
        if (answer.length() == 1)
            switch (tolower(answer[0])) {
                case 'y':
                    return true;
                case 'n':
                    return false;
            }
        std::cout << "Invalid input: " << answer << " Please enter 'y' for yes or 'n' for no.\n";
    }
}
