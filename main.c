#include "fiddling.c"
#include "runtime.c"

void bit_test_function() {
    for (int i = 0; i < BILLION; i++) {
        add1(i);
    }
}

void reg_test_function() {
    for (int i = 0; i < BILLION; i++) {
        add1reg(i);
    }
}

int main() {
    print_runtime(bit_test_function);
    print_runtime(reg_test_function);

    return 0;
}