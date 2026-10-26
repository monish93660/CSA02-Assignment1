#include <stdio.h>
#include <stdlib.h>

/* Demo: read tariff values at run time; readings are watt-hours.
   Input: normal tariff paise/kWh, fixed charge paise, then interval records:
   watt-hours used and peak flag (1=18:00-22:00, 0=other time). */
int main(void) {
    long normal_rate_paise, fixed_paise;
    int intervals;
    printf("Enter normal tariff (paise/kWh) and fixed charge (paise): ");
    if (scanf("%ld %ld", &normal_rate_paise, &fixed_paise) != 2 ||
        normal_rate_paise < 0 || fixed_paise < 0) {
        printf("Invalid tariff input\n"); return 1;
    }
    printf("Enter number of intervals: ");
    if (scanf("%d", &intervals) != 1 || intervals < 0) {
        printf("Invalid interval count\n"); return 1;
    }
    long long normal_wh = 0, peak_wh = 0;
    for (int i = 0; i < intervals; i++) {
        long long wh;
        int peak;
        printf("Interval %d: enter watt-hours and peak flag (0/1): ", i + 1);
        if (scanf("%lld %d", &wh, &peak) != 2 || wh < 0 || (peak != 0 && peak != 1)) {
            printf("Invalid interval data\n"); return 1;
        }
        if (peak) peak_wh += wh;
        else normal_wh += wh;
    }
    /* Keep the 20% peak surcharge exact in paise using integer arithmetic.
       Base charge is rounded to the nearest paise once per category. */
    long long normal_charge = (normal_wh * normal_rate_paise + 500LL) / 1000LL;
    long long peak_charge = (peak_wh * normal_rate_paise * 120LL + 50000LL) / 100000LL;
    long long total = fixed_paise + normal_charge + peak_charge;
    printf("Normal use: %lld Wh\nPeak use: %lld Wh\n", normal_wh, peak_wh);
    printf("Total bill: Rs %lld.%02lld\n", total / 100, total % 100);
    return 0;
}
