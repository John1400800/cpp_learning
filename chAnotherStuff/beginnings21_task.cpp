#include <cstdlib>
#include <cstdint>
#include <cassert>
#include <utility>
#include <iostream>

class CStringWrapper {
    char *str  { nullptr };
    size_t size{ 0 };

    static constexpr size_t getCStrSize(const char *str) {
        if (str==nullptr)
            return 0;
        size_t i{0};
        for (; str[i]!='\0'; ++i)
            ;
        return i;
    }
public:
    CStringWrapper(size_t iniSize)
        : size{ iniSize }
    {
        str = new char[size+1];
        str[size] = '\0';
    }

    CStringWrapper(const char* src)
        : CStringWrapper(getCStrSize(src))
    {
        for (size_t i{0}; i<size; ++i)
            str[i] = src[i];
    }

    CStringWrapper(const CStringWrapper& other)
        : CStringWrapper(other.size)
    {
        for (size_t i{0}; i<size; ++i)
            str[i] = other[i];
    }

    CStringWrapper(CStringWrapper&& other) noexcept
        : str{other.str}, size{other.size}
    {
        other.str = nullptr;
        other.size = 0;
    }

    // implement the copy assignment operator and the move assignment operator

    char& operator[](size_t idx) {
        assert(idx < size);
        return str[idx];
    }

    char operator[](size_t idx) const {
        assert(idx < size);
        return str[idx];
    }

    friend std::ostream& operator<<(std::ostream& out, const CStringWrapper& str) {
        if (str.str == nullptr)
            return out << "str is empty"; // debug
        for (size_t i{0}; i<str.size; ++i)
            std::cout << str[i];
        return out;
    }
};

int main(int32_t, const char**) {
    CStringWrapper str{"hello world!"};
    CStringWrapper str2{std::move(str)};
    std::cout << str2 << str << '\n';
    return EXIT_SUCCESS;
}
