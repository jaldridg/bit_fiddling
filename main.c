#include "fiddling.c"
#include "runtime.c"

void bit_test_function() {
    for (int j = 0; j < 1000; j += 7) {
        add1(j);
    }
}

void reg_test_function() {
    for (int j = 0; j < 1000; j += 7) {
        add1reg(j);
    }
}

int main() {
    print_runtime(bit_test_function);
    print_runtime(reg_test_function);

    return 0;
}