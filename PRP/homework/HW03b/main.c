#include <stdio.h>

int main(void)
{
    int cislo;
    int predchozi = -1;
    int delka = 0;

    while (scanf("%d", &cislo) == 1) {
        if (cislo < 0 || cislo > 100) {
            if (delka > 1) {
                printf("%dx %d\n", delka, predchozi);
            }
            printf("Error: Vstup je mimo interval!\n");
            return 100;
        }

        if (cislo == predchozi) {
            delka++;
        } else {
            if (delka > 1) {
                printf("%dx %d\n", delka, predchozi);
            }
            delka = 1;
        }

        predchozi = cislo;
    }

    if (delka > 1) {
        printf("%dx %d\n", delka, predchozi);
    }

    return 0;
}
