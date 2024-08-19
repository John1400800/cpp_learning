#include <cstdlib>
#include <cstdint>
#include <vector>
#include <iostream>

constexpr void printStack(const std::vector<auto>& stack) {
    if (stack.empty()) // if (stack.size() == 0)
        std::cout << "printStack(): stack empty\n";
    for (auto item {stack.begin()}; item != stack.end(); ++item)
        std::cout << *item << (item == stack.end()-1 ? "\n" : ", ");
    std::cout << "capacity: " << stack.capacity() << ", size: " << stack.size() << '\n';
}

int main() {
    std::vector<uint32_t> stack{};
    stack.reserve(3);
    printStack(stack);
    stack.push_back(1);
    printStack(stack);
    stack.push_back(2);
    printStack(stack);
    stack.push_back(3);
    printStack(stack);
    std::cout << "Top: " << stack.back() << '\n'; // back() returns the last element
    stack.pop_back();
    printStack(stack);
    stack.pop_back();
    printStack(stack);
    stack.pop_back();
    printStack(stack);
    return EXIT_SUCCESS;
}
