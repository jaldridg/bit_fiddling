#include "fiddling.c"
#include "runtime.c"

void test_function() {
    for (int i = 0; i < 1000000000; i += 2) {
        div2(i);
    }
}

void test_function_2() {
    for (int i = 0; i < 1000000000; i += 2) {
        div2reg(i);
    }
}

int main() {
    void (*runtime_function)() = test_function;
    print_runtime(runtime_function);

    void (*runtime_function_2)() = test_function_2;
    print_runtime(runtime_function_2);

    return 0;
}