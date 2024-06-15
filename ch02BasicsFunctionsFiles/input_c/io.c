#include "io.h"
#include <stdio.h>

#define BUF_SIZE 1024

#define NEXT_DIGIT(res, ch)             \
    do {                                \
        (res) = (res)*10 + (ch) - '0';  \
    } while (0)

#define IS_DIGIT(c)                     \
    ((c) >= '0' && (c) <= '9')

#define IS_SPACE(c)                     \
    ((c) == ' ' || (unsigned)(c)-'\t' < 5)

static void reset_flags();
static bool valid_input(int ch);

bool read_int(int *res) {
    bool valid, minus, start;
    int ch;
    for (valid=start=true, minus=false, *res=0, reset_flags(); valid; ) {
        ch = getchar();
        if ((valid = valid_input(ch))) {
            if (ch == '-')
                minus = true;
            else if (ch != '+')
                NEXT_DIGIT(*res, ch);
        } else if (IS_SPACE(ch) && !start) {
            valid = true;
            break;
        }
        start=false;
    }
    if (minus)
        *res = -*res;
    return valid;
}

static bool minus_flag = false;

void reset_flags() {
    minus_flag = false;
}

bool valid_input(int ch) {
    if (ch=='-') {
        if (!minus_flag)
            minus_flag=true;
        else
            return false;
    } else if (!IS_DIGIT(ch) && ch!='+')
        return false;
    return true;
}
