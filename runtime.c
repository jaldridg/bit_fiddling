#include <time.h>

#define MILLION 1000000
#define BILLION 1000000000

void print_runtime(void (*func)()) {
    clock_t start_time = clock();

    func();

    clock_t end_time = clock();
    float time = (float)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time: %f\n", time);
}