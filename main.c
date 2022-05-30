#include "fiddling.c"
#include "runtime.c"

#include <assert.h>

void test_success(unsigned int (*func_1)(unsigned int), 
                  unsigned int (*func_2)(unsigned int)) {
    for (int i = 0; i < BILLION; i++) {
        assert(func_1(i) == func_2(i));
    }
}

void bit_test_function() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < BILLION; j++) {
            div3(j);
        }
    }
}

void reg_test_function() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < BILLION; j++) {
            div3reg(j);
        }
    }
}

int main() {
    test_success(div3, div3reg);
    print_runtime(bit_test_function);
    print_runtime(reg_test_function);

    return 0;
}