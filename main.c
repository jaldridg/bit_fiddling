#include "fiddling.c"
#include "runtime.c"

#include <assert.h>

void test_success(unsigned int (*func_1)(unsigned int), 
                  unsigned int (*func_2)(unsigned int)) {
    for (int i = 0; i < BILLION; i++) {
        assert(func_1(i) == func_2(i));
    }
}

/*
 * Tests the function over a range of small and large numbers
 */
void test_function(unsigned int (*operation_func)(unsigned int)) {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < BILLION; j++) {
            operation_func(j);
        }
    }
}

/*
 * Tests the function over a range of small numbers
 */
void test_function_small(unsigned int (*operation_func)(unsigned int)) {
    for (int i = 0; i < (1 << 17); i++) {
        for (int j = 0; j < (1 << 16); j++) {
            operation_func(j);
        }
    }
}

/*
 * Tests the function over a range of large numbers
 */
void test_function_large(unsigned int (*operation_func)(unsigned int)) {
    for (int i = 0; i < 10; i++) {
        for (int j = (1 << 16); j < (1 << 31); j++) {
            operation_func(j);
        }
    }
}

int main() {
    // Function pointers to the bitwise and regular operations
    unsigned int (*bit_op)(unsigned int) = mult30;
    unsigned int (*reg_op)(unsigned int) = mult30reg;

    // Function pointers to runtime test functions
    void (*bit_test_func)(unsigned int (*bit_operation)(unsigned int)) = test_function(mult30);
    void (*reg_test_func)(unsigned int (*reg_operation)(unsigned int)) = test_function(mult30reg);

    test_success(bit_op, reg_op);
    print_runtime(test_function(bit_op));
    print_runtime(test_function(reg_op));

    return 0;
}