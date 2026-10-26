#include <stdio.h>
int main(void) {
    printf("7 / 2 = %d (integer division)\n", 7 / 2);
    printf("(double)7 / 2 = %.2f\n", (double)7 / 2);
    printf("0.1 + 0.2 = %.17f (binary floating-point approximation)\n", 0.1 + 0.2);
    printf("(int)3.99 = %d (fraction is discarded)\n", (int)3.99);
    return 0;
}
