#include <stdio.h>

int main (void) {   
    // int i; //deklarace pred cyklem, abychom ho videli po cyklu
    // for(int i = 1; i <= 10; i++) 
    // {
    //     if (i == 3)
    //         continue; //ukonci iteraci ale cyklus jede dal
    //     if (i == 8)
    //         break; //vyskoci z cyklu
    //     printf(" %d", i);
    // }
    // printf(" i po cyklu = %d", i);


    //SUMA CISEL
    int n;
    int suma = 0;
    printf("Zadejte kladne cislo: \n");
    scanf("%d", &n );

    for (int j = 0; j <= n; j++)
        suma += j;

    
    int tmp = 1;
    for (int j = 0; j <= n; j++)
    {
        printf(" %+2d", tmp);
        tmp *= -1;
    }
    printf("Suma cisel od 0 do %d je %d \n", n, suma);

    return 0;

}