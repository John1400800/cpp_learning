#include <cstdlib>
#include <cstdint>
#include <iostream>

template <typename T=uint32_t>
class Foo {
    // if not static, then the static function will not be able to access
    static constexpr auto defBar_{1}, defBaz_{2};
    T bar_{}, baz_{};
public:
    Foo(T bar=defBar_, T baz=defBaz_)
        : bar_{bar}, baz_{baz} {}
    friend std::ostream& operator<<(std::ostream& out, const Foo<T>& foo) {
        return out << "bar: " << foo.bar_ << ", baz: " << foo.baz_;
    }
    static consteval auto defBar() {
        return defBar_;
    }
    static consteval auto defBaz() {
        return defBaz_;
    }
};

int main() {
    Foo<uint32_t> foo{2, 3};
    std::cout << foo << '\n';
    return EXIT_SUCCESS;
}
