#include <cstdlib>
#include <cstdint>

class Base {
public:
    uint32_t m_public{};
protected:
    uint32_t m_protected{};
private:
    uint32_t m_private{};
};

class Pri: private Base {
public:
    Pri() {
        m_public    = 1; // allowed: can access public Base members from derived class
        m_protected = 2; // allowed: can access protected Base members from derived class
        m_private   = 3; // not allowed: can not access private Base members from derived class
    }
};

int main() {
    Base base;
    base.m_public = 1; // okay: m_public is public in Base
    base.m_protected = 2; // not okay: m_protected is protected in Base
    base.m_private = 3; // not okay: m_private is private in Base

    Pri pri;
    pri.m_public = 1; // not okay: m_public is now private in Pri
    pri.m_protected = 2; // not okay: m_protected is now private in Pri
    pri.m_private = 3; // not okay: m_private is inaccessible in Pri
    return EXIT_SUCCESS;
}
