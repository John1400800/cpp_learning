#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

static size_t countDigits(uint8_t num);

int main(void) {
#if 0
#define UPPER 10
#define UPPER_COUNT_DIGITS countDigits(UPPER-1)
#define LENGTH 3
    uint8_t count;
    for (count=0; count<UPPER; ++count) {
        printf("%*d", UPPER_COUNT_DIGITS, count);
        putchar((count%LENGTH==LENGTH-1 || count==UPPER-1)?'\n':' ');
    }
#else
#define LIMIT 5
#define LIMIT_COUNT_DIGITS countDigits(LIMIT)
    for (int8_t outer=1; outer<=LIMIT; ++outer) {
        for (int8_t space=LIMIT-outer; space>0; --space)
            printf("%*s ", LIMIT_COUNT_DIGITS, "");
        for (int8_t inner=1; inner<=outer; ++inner)
            printf(inner!=outer?"%*d ":"%*d\n", LIMIT_COUNT_DIGITS, inner);
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
