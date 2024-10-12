#include <stdlib.h>

class Base {
public:
    uint32_t public_{};
protected:
    uint32_t protected_{};
private:
    uint32_t private_{};
};

class Derived: public Base {
    Derived() {
        public_    = 1; // allowed: can access public Base members from derived class
        protected_ = 1; // allowed: can access protected Base members from derived class
        private_   = 1; // not allowed: can not access private Base members from derived class
    }
};

int main() {
    Base base;
    base.public_        = 1; // allowed: can access public members from outside class
    base.protected_     = 1; // not allowed: can not access protected members from outside class
    base.private_       = 1; // not allowed: can not access private members from outside class

    return EXIT_SUCESS;
}
