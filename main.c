#include "fiddling.c"
#include "runtime.c"

#include <assert.h>

void test_success(unsigned int (*func_1)(unsigned int), 
                  unsigned int (*func_2)(unsigned int)) {
    for (int i = 0; i < 100; i++) {
        assert(func_1(i) == func_2(i));
    }
}

void bit_test_function() {
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < MILLION; j++) {
            mult9(j);
        }
    }
}

void reg_test_function() {
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < MILLION; j++) {
            mult9reg(j);
        }
    }
}

void reg_test_function2() {
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < MILLION; j++) {
            mult2faster(j);
        }
    }
}

int main() {
    test_success(add1, add1reg);
    print_runtime(bit_test_function);
    print_runtime(reg_test_function);

    return 0;
}