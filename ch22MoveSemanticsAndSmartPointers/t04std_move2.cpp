#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include <utility>

std::ostream& operator<<(std::ostream&, std::vector<std::string>&);

int main() {
    std::string str{ "Knock" };
    std::vector<std::string> vec;
    std::cout << "Copying str\n";
    // calls l-value version of push_back, which copies str into the array element
    vec.push_back(str);
    std::cout << "str: " << str << "\n"
                 "vec: " << vec << '\n';
    std::cout << "\nMoving str\n";
    vec.push_back(std::move(str));
    std::cout << "str: " << str << "\n"
                 "vec: " << vec << '\n';
    return  EXIT_SUCCESS;
}

std::ostream& operator<<(std::ostream& out, std::vector<std::string>& vec) {
    for (size_t i{0}; i < vec.size(); ++i)
        std::cout << (i > 0? ", " : "") << vec[i];
    return out;
}
