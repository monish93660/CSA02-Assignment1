#include <stdio.h>
#define RUPEES_TO_PAISE(x) ((long)(x) * 100L)
#define SQUARE(x) ((x) * (x))
#define MAX_VALUE(a, b) (((a) > (b)) ? (a) : (b))

static inline int square_fn(int x) { return x * x; }
static inline int max_fn(int a, int b) { return a > b ? a : b; }

int main(void) {
    int a = 4, b = 7;
    printf("5 rupees = %ld paise\n", RUPEES_TO_PAISE(5));
    printf("SQUARE(a + 1) = %d\n", SQUARE(a + 1));
    printf("MAX_VALUE(a, b) = %d\n", MAX_VALUE(a, b));
    printf("square_fn(a + 1) = %d\n", square_fn(a + 1));
    printf("max_fn(a, b) = %d\n", max_fn(a, b));
    return 0;
}
