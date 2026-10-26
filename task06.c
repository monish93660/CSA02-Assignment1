#include <stdio.h>
int main(void) {
    int household;
    unsigned int units;
    long total_paise;
    printf("Enter household number and units consumed: ");
    if (scanf("%d %u", &household, &units) != 2) {
        printf("Invalid input. Enter numeric values.\n");
        return 1;
    }
    total_paise = 5000L;
    if (units > 100) {
        unsigned int slab2 = units < 200 ? units - 100 : 100;
        total_paise += (long)slab2 * 225L;
    }
    if (units > 200) total_paise += (long)(units - 200) * 450L;
    printf("Household: %d\nUnits: %u\nBill: Rs %ld.%02ld\n",
           household, units, total_paise / 100, total_paise % 100);
    return 0;
}
