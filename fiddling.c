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

unsigned int mult9(unsigned int input) {
    return (input << 3) + input;
}

unsigned int div3(unsigned int input) {
    // 1431655785 was obtained from taking the maximum unsigned int divided by 3
    // Apparently, compilers do something like this instead of dividing
    return (uint32_t)(((uint64_t)input + 1) * 1431655765 >> 32);
}

unsigned int mult30(unsigned int input) {
    return (input << 5) - (input << 1);
}

unsigned int mult30reg(unsigned int input) {
    return input * 30;
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