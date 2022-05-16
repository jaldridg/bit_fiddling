#include "fiddling.c"
#include "runtime.c"

void bit_test_function() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < BILLION; j++) {
            add1(j);
        }
    }
}

void reg_test_function() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < BILLION; j++) {
            add1reg(j);
        }
    }
}

int main() {
    print_runtime(bit_test_function);
    //print_runtime(reg_test_function);

    return 0;
}