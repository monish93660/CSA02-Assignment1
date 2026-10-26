#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef unsigned short meter_t;
static unsigned int units_used(meter_t previous, meter_t current) {
    return (meter_t)(current - previous);
}
static long bill_paise(unsigned int units) {
    long p = 5000L;
    if (units > 100) {
        unsigned int slab = units < 200 ? units - 100 : 100;
        p += (long)slab * 225L;
    }
    if (units > 200) p += (long)(units - 200) * 450L;
    return p;
}
int main(void) {
    unsigned int prev, curr;
    printf("Enter previous and current meter readings (0-65535): ");
    if (scanf("%u %u", &prev, &curr) != 2 || prev > USHRT_MAX || curr > USHRT_MAX) {
        printf("Invalid input\n"); return 1;
    }
    if (curr < prev && !(prev >= 65000U && curr <= 1000U)) {
        printf("Invalid decreasing reading: rollover not plausible\n"); return 1;
    }
    unsigned int units = units_used((meter_t)prev, (meter_t)curr);
    long p = bill_paise(units);
    printf("Units consumed: %u\nBill: Rs %ld.%02ld\n", units, p / 100, p % 100);
    return 0;
}
