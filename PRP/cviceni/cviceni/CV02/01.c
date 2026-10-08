#include <stdio.h>

int main(void){

    printf("Ahoj svete!\n");
    printf("Ahoj svete!\r");
    printf("Nazdar\n");
    
    int cislo = 123;
    char znak = 'm';
    printf("Znak jako cislo: %d\n char");
    printf("Znak jako znak: %c\n char");
    printf("Znak jako hex: %x\n char");

    float pi_f = 3.14159269;
    double pi = 3.14159269;
    printf("pi jako float %f\n:", pi_f);
    printf("pi jako double %lf\n:", pi_f);

    return 0;
}

