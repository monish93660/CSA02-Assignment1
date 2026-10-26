#include <stdio.h>
#define FIXED_CHARGE_PAISE 5000L
#define RATE2_PAISE 225L
#define RATE3_PAISE 450L

static long bill_paise(unsigned int units) {
    long p = FIXED_CHARGE_PAISE;
    if (units > 100) {
        unsigned int n = units < 200 ? units - 100 : 100;
        p += (long)n * RATE2_PAISE;
    }
    if (units > 200) p += (long)(units - 200) * RATE3_PAISE;
    return p;
}
int main(void) {
    unsigned int units;
    printf("Enter units consumed: ");
    if (scanf("%u", &units) != 1) {
        printf("Invalid input\n"); return 1;
    }
    long p = bill_paise(units);
    printf("Bill: Rs %ld.%02ld\n", p / 100, p % 100);
    return 0;
}
