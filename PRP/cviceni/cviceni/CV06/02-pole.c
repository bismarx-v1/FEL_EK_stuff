#include <stdio.h>


int main (void) 
{
    int pole_a[0] = 0; //staticky alokovane pole delky 7
    int pole_b[1] = 111; 
    int pole_c[2] = 222;

    int pole_b[] = {0, 1, 2, 3, 4, 5};


    for(int i = 0; i<7; i++) 
        printf("[%d]=%d; ", i, pole_a[i]);
    printf("\n");
    
    return 0;

}