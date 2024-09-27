#include <cstdlib>
#include <cstdint>
#include <iostream>

struct Res {
    uint32_t res{};
    bool prom{};
};

Res fibSeqNum(uint32_t count) {
    if (count==1) {
        std::cout << "fibSeqNum(1) return 0\n";
        return {0, true};
    }
    if (count==2) {
        std::cout << "fibSeqNum(2) return 1\n";
        return {1, true};
    }
    std::cout << "fibSeqNum("<<count<<") called, return fibSeqNum("<<count-1<<") + fibSeqNum("<<count-2<<")\n";
    Res prev{fibSeqNum(count-1)}, befPrev{fibSeqNum(count-2)};
    if (prev.prom && befPrev.prom)
        std::cout << "fibSeqNum("<<count<<") return fibSeqNum("<<count-1<<") + fibSeqNum("<<count-2<<")"
            ", which is "<<prev.res<<" + "<<befPrev.res<<" = "<<prev.res+befPrev.res<<'\n';
    return {prev.res+befPrev.res, prev.prom && befPrev.prom? true : false};
}

int main() {
    std::cout << fibSeqNum(5).res << '\n';
    return EXIT_SUCCESS;
}
