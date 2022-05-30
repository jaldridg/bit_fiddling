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

unsigned int div3(unsigned int input) {
    // 1431655785 was obtained from taking the maximum unsigned int divided by 3
    return (uint32_t)(((uint64_t)input + 1) * 1431655765 >> 32);
}

unsigned int div3reg(unsigned int input) {
    return input / 3;
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