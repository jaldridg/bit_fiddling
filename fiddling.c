#include "fiddling.h"

unsigned int div2(unsigned int input) {
    return input >> 1;
}

unsigned int add1(unsigned int input) {
     // Isolate rightmost 0-bit
    unsigned int temp = ~input & (input + 1);

    // Right propogate rightmost 1-bit then XOR
    return input ^ (temp | (temp - 1)); 
}

unsigned int add1reg(unsigned int input) {
    return input + 1;
}

unsigned int mult9(unsigned int input) {
    return (input << 3) + input;
}

unsigned int mult9reg(unsigned int input) {
    return input * 9;
}

/*
 *  Prints the given least significant number of bits of the given integer number
 */
void bprint(unsigned int num, unsigned int bits) {
    assert (~((bits - 1) >> 5)); // Makes sure there are under 32 bits
    while (bits--) {
        printf("%d", ((num >> bits) & 1) ? 1 : 0);
    }
}