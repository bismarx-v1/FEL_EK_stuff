#include <stdio.h>

int main (void) 
{   
    int n;
    int citatel = 4;
    int jmenovatel = 1;
    double pi = 0;

    printf("kolik prvku rady?\n");
    scanf("%d", &n);

    for(int k = 0; k <n; k++)
    {
        pi +=((double) citatel) / jmenovatel;
        printf("k = %8d, cit = %d, jme = %8d, pi = %.10f\n ", k, citatel, jmenovatel, pi);
        citatel *= -1;
        jmenovatel += 2;
    }

    printf("n = %8d, pi = %.10f\n", n, pi);
    return 0;

}
