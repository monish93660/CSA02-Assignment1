#include <stdio.h>
#include "billing.h"

long compute_energy_paise(unsigned int units) {
    long energy = 0;
    if (units > 200) energy += (long)(units - 200) * 450L;
    if (units > 100) {
        unsigned int slab = units < 200 ? units - 100 : 100;
        energy += (long)slab * 225L;
    }
#ifdef DEBUG
    fprintf(stderr, "[DEBUG] units=%u energy_paise=%ld\n", units, energy);
#endif
    return energy;
}
int main(void) {
    unsigned int units = 150;
    long total = FIXED_CHARGE_PAISE + compute_energy_paise(units);
    printf("Units: %u\nTotal bill: Rs %ld.%02ld\n",
           units, total / 100, total % 100);
    return 0;
}
