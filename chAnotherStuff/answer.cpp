#include <cstdlib>
#include <cstdint>
#include <cctype>
#include <limits>
#include <string_view>
#include <iostream>

bool askYesNo(std::string_view question, std::ostream& =std::cout, std::istream& =std::cin);

int main(int32_t, const char**) {
    bool answer{ askYesNo("just answer") };
    std::cout << std::boolalpha << answer <<'\n';
    return EXIT_SUCCESS;
}

bool askYesNo(std::string_view question, std::ostream& out, std::istream& in) {
    char answer{};
    while (true) {
        out << question << " (y/n): ";
        in >> answer;
        if (in.fail())
            in.clear();
        else
            switch (tolower(answer)) {
            case 'y':
                return true;
            case 'n':
                return false;
        }
        in.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        out << "Invalid input. Please enter 'y' for yes or 'n' for no.\n";
    }
}
