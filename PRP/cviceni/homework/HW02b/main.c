#include <stdio.h>

int main(void)
{
    int a;
    int b;
    int c;

    if (scanf("%d %d %d", &a, &b, &c) != 3) {
        return 0;
    }

    int d = b * b - 4 * a * c;

    if (d < -999 || d > 999) {
        printf("Diskriminant mimo povoleny interval!\n");
        return 0;
    }

    const char *koreny;
    if (d > 0) {
        koreny = "Dva realne koreny";
    } else if (d == 0) {
        koreny = "Jeden koren";
    } else {
        koreny = "Dva imaginarni koreny";
    }

    printf("+-----+-----+-----+-----+\n");
    printf("|%4d |%4d |%4d |%4d |\n", a, b, c, d);
    printf("+-----+-----+-----+-----+\n");
    printf("| %21s |\n", koreny);
    printf("+-----------------------+\n");

    return 0;
}