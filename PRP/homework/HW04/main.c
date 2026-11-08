#include <stdio.h>

#define MAX_DELKA 255

/* Vypise jednu posloupnost a vrati pocet zapsanych symbolu. */
int vypis_posloupnost(int symbol, int delka)
{
    int zapsano = 0;

    if (delka == 1) {
        putchar(symbol);
        zapsano = 1;
    } else if (delka == 2) {
        putchar(symbol);
        putchar(symbol);
        zapsano = 2;
    } else if (delka >= 3) {
        zapsano = printf("%c%d", symbol, delka);
    }

    return zapsano;
}

int main(void)
{
    int znak;
    int symbol = 0;
    int delka = 0;
    int vstupnich = 0;
    int zakodovanych = 0;

    while ((znak = getchar()) != EOF && znak != '\n') {
        if (znak < 'A' || znak > 'Z') {
            zakodovanych += vypis_posloupnost(symbol, delka);
            fprintf(stderr, "Error: Neplatny symbol!\n");
            return 100;
        }

        vstupnich++;

        if (znak == symbol) {
            delka++;
        } else {
            zakodovanych += vypis_posloupnost(symbol, delka);
            symbol = znak;
            delka = 1;
        }

        if (delka == MAX_DELKA) {
            zakodovanych += vypis_posloupnost(symbol, delka);
            delka = 0;
        }
    }

    zakodovanych += vypis_posloupnost(symbol, delka);
    putchar('\n');

    fprintf(stderr, "Pocet vstupnich symbolu: %d\n", vstupnich);
    fprintf(stderr, "Pocet zakodovanych symbolu: %d\n", zakodovanych);
    if (vstupnich > 0) {
        fprintf(stderr, "Kompresni pomer: %.2f\n", (double)zakodovanych / vstupnich);
    }

    return 0;
}
