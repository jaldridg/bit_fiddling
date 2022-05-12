#include "fiddling.h"

int div2(int input) {
    return input >> 1;
}

int div2reg(int input) {
    return input / 2;
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