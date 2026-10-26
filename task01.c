#include <stdio.h>
int main(void) {
    int household;
    unsigned int previous, current, units;
    long energy_paise, fixed_paise = 5000L, total_paise;

    printf("Enter household number, previous reading and current reading: ");
    if (scanf("%d %u %u", &household, &previous, &current) != 3) {
        printf("Invalid input\n");
        return 1;
    }
    if (current < previous) {
        printf("Invalid reading: rollover handling is required\n");
        return 1;
    }
    units = current - previous;
    if (units <= 100) energy_paise = 0;
    else if (units <= 200) energy_paise = (long)(units - 100) * 225L;
    else energy_paise = 100L * 225L + (long)(units - 200) * 450L;
    total_paise = fixed_paise + energy_paise;

    printf("Household: %d\nUnits consumed: %u\nEnergy charge: Rs %ld.%02ld\n",
           household, units, energy_paise / 100, energy_paise % 100);
    printf("Fixed charge: Rs %ld.%02ld\nTotal bill: Rs %ld.%02ld\n",
           fixed_paise / 100, fixed_paise % 100,
           total_paise / 100, total_paise % 100);
    return 0;
}
