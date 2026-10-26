#include <stdio.h>
int main(void) {
    const int bills = 4000;
    const long bill_paise = 16250L; /* Rs 162.50 per bill */
    long long exact_total_paise = (long long)bills * bill_paise;
    double total_rupees = (double)bills * 162.50;
    printf("Bills: %d\n", bills);
    printf("Integer-paise total: Rs %lld.%02lld\n",
           exact_total_paise / 100, exact_total_paise % 100);
    printf("Double total: Rs %.2f\n", total_rupees);
    printf("long long size: %zu bytes\n", sizeof(long long));
    return 0;
}
