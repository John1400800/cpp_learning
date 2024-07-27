#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

static size_t countDigits(uint8_t num);

int main(void) {
#if 1
#define UPPER 10
#define UPPER_COUNT_DIGITS countDigits(UPPER-1)
#define LENGTH 3
    uint8_t count;
    for (count=0; count<UPPER; ++count) {
        printf("%*d", UPPER_COUNT_DIGITS, count);
        putchar((count%LENGTH==LENGTH-1 || count==UPPER-1)?'\n':' ');
    }
#else
#define LIMIT 10
#define LIMIT_COUNT_DIGITS countDigits(LIMIT)
    uint8_t inner, outer;
    for (outer=1; outer<=LIMIT; ++outer) {
        for (inner=1; inner<=outer; ++inner)
            printf("%*d ", LIMIT_COUNT_DIGITS, inner);
        putchar('\n');
    }
#endif
    return EXIT_SUCCESS;
}

static size_t countDigits(uint8_t num) {
    size_t count;
    for (count=1; num>=10; num/=10)
        ++count;
    return count;
}
