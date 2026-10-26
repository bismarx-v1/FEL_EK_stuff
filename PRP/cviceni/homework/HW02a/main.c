#include <stdio.h>

int main(void)
{
    int a;
    int b;

    if (scanf("%d %d", &a, &b) != 2) {
        return 0;
    }

    if (a <= 10000 && a >= -10000 && b <= 10000 && b >= -10000) {
        printf("Desitkova soustava: %d %d\n", a, b);
        printf("Sestnactkova soustava: %x %x\n", a, b);
        printf("Soucet: %d + %d = %d\n", a, b, a + b);
        printf("Rozdil: %d - %d = %d\n", a, b, a - b);
        printf("Soucin: %d * %d = %d\n", a, b, a * b);
        if (b == 0) {
            printf("Nedefinovany vysledek!\n");
        } else {
            printf("Podil: %d / %d = %d\n", a, b, a / b);
        }
        printf("Prumer: %.1f\n", (a + b) / 2.0);
    } else {
        printf("Vstup je mimo interval!\n");
    }

    return 0;
}
