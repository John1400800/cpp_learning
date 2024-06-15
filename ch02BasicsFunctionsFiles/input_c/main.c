#include "io.h"
#include <stdlib.h>
#include <stdio.h>

int main(void) {
    int i, nums[3];
    for (i=0; i<3; ++i)
        while (!read_int(&nums[i]))
            ;
    printf("%d\n", nums[0]+nums[1]+nums[2]);
    return EXIT_SUCCESS;
}
