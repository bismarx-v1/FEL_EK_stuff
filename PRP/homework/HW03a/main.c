#include <stdio.h>

int main(void)
{
    int cislo;
    int pocet = 0;
    int kladnych = 0;
    int zapornych = 0;
    int sudych = 0;
    int lichych = 0;
    int soucet = 0;
    int maximum = 0;
    int minimum = 0;

    while (scanf("%d", &cislo) == 1) {
        if (cislo < -10000 || cislo > 10000) {
            printf("\nError: Vstup je mimo interval!\n");
            return 100;
        }

        if (pocet > 0) {
            printf(", ");
        }
        printf("%d", cislo);

        if (pocet == 0 || cislo > maximum) {
            maximum = cislo;
        }
        if (pocet == 0 || cislo < minimum) {
            minimum = cislo;
        }

        pocet++;
        soucet += cislo;
        if (cislo > 0) {
            kladnych++;
        } else if (cislo < 0) {
            zapornych++;
        }
        if (cislo % 2 == 0) {
            sudych++;
        } else {
            lichych++;
        }
    }

    printf("\n");
    printf("Pocet cisel: %d\n", pocet);
    printf("Pocet kladnych: %d\n", kladnych);
    printf("Pocet zapornych: %d\n", zapornych);
    if (pocet > 0) {
        printf("Procento kladnych: %.2f\n", 100.0 * kladnych / pocet);
        printf("Procento zapornych: %.2f\n", 100.0 * zapornych / pocet);
    }
    printf("Pocet sudych: %d\n", sudych);
    printf("Pocet lichych: %d\n", lichych);
    if (pocet > 0) {
        printf("Procento sudych: %.2f\n", 100.0 * sudych / pocet);
        printf("Procento lichych: %.2f\n", 100.0 * lichych / pocet);
        printf("Prumer: %.2f\n", (double)soucet / pocet);
        printf("Maximum: %d\n", maximum);
        printf("Minimum: %d\n", minimum);
    }

    return 0;
}
