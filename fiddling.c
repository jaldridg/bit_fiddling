#include "fiddling.h"

int div2(unsigned int input) {
    return input >> 1;
}

int add1(unsigned int input) {
    char i = 0;
    printf("in %d\t", input);
    do {
        input ^= (1 << i);
    } while (input & (1 << i++));
    printf("out %d\n", input);
    return input;
}

int add1reg(int input) {
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