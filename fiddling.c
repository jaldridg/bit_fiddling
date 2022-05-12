#include "fiddling.h"

int div2(unsigned int input) {
    return input >> 1;
}

int add1(unsigned int input) {
    // If odd, things are interesting
    if (input & 1) {
        char i = 0;
        while (input & (1 << i++));
        //int i_mask = ~((1 << i) - 1);
        int out = (input & ~((1 << i) - 1)) | (~input & ((1 << i) - 1));
        printf("in %d\tout %d\n", input, out);
        b_print(out, 32);
        return out;
    }
    printf("in %d\tout %d\n", input, input | 1);
    return input | 1;
}

int add1reg(int input) {
    printf("in %d\tout %d\n", input, input + 1);
    return input + 1;
}

/*
 *  Prints the given least significant number of bits of the given integer number
 */
void b_print(unsigned int num, unsigned int bits) {
    assert (~((bits - 1) >> 5)); // Makes sure there are under 32 bits
    while (bits--) {
        printf("%d", ((num >> bits) & 1) ? 1 : 0);
    }
}