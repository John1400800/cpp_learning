#include <cstdlib>
#include <vector>
#include <string>
#include <functional>   // std::reference_wrapper
#include <memory>       // for std::make_unique
#include <iostream>

int main() {
    std::string tom     {   "Tom" };
    std::string berta   { "Berta" };
    // these string are sorted by reference, not value
    std::vector<std::reference_wrapper<std::string>> names{ tom, berta };
    std::string jim     {   "Jim" };
    names.emplace_back( berta);
    for (auto name : names)
        name.get() +=  " Beam";
    std::cout << tom << '\n';
    return EXIT_SUCCESS;
}
