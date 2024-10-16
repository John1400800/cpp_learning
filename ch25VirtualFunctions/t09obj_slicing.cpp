#include <functional>
#include <cstdlib>
#include <cstdint>
#include <vector>
#include <iostream>

class Base {
protected:
    uint32_t m_value{};
public:
    Base(uint32_t value)
        : m_value{ value }
    { }

    virtual std::string_view getName() const {
        return "Base";
    }

    uint32_t getValue() const {
        return m_value;
    }

    virtual ~Base() = default;
};

class Derived: public Base {
public:
    Derived(uint32_t value)
        : Base{ value }
    { }

    std::string_view getName() const override {
        return "Derived";
    }
};

// #define REF_IMPL
#ifdef REF_IMPL
using RefPtr_t = std::reference_wrapper<Base>;
#else
using RefPtr_t = Base *;
#endif

int main() {
    std::vector<RefPtr_t> vec{};
    Base b{5};
    Derived d{6};
#ifdef REF_IMPL
    vec.push_back(b);
    vec.push_back(d);
#else
    vec.push_back(&b);
    vec.push_back(&d);
#endif
    for (const RefPtr_t elenent : vec)
        std::cout << "I am a "
#ifdef REF_IMPL
            << elenent.get().getName()
#else
            << elenent->getName()
#endif
            << " with value "
#ifdef REF_IMPL
            << elenent.get().getValue()
#else
            << elenent->getValue()
#endif
            << '\n';
    return EXIT_SUCCESS;
}
