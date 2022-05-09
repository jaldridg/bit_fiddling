#include "fiddling.c"
#include "runtime.c"

void test_function() {
    for (int i = 0; i < 1000000000; i += 2) {
        div2(i);
    }
}

int main() {
    void (*runtime_function)() = test_function;
    print_runtime(runtime_function);

    return 0;
}