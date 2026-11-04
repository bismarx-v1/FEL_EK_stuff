#include <stdio.h>

void tisk (int* pole, size_t delka) //size_t je obvykle alias pro unsigned long
{
    for (int i = 0;)
}

int main (void) 
{
    int pole_a[7];
    pole_a[0] = 0; //staticky alokovane pole delky 7
    pole_a[1] = 111; 
    pole_a[2] = 222;

    int pole_b[] = {0, 1, 2, 3, 4, 5};
    int pole_c[6] = {0.1,2}; //definujeme pocatecni prvky  a delku pole, vyplni se nulama

    for(int i = 0; i<7; i++) 
        printf("[%d]=%d; ", i, pole_a[i]);
    printf("\n");
    

    printf("C: ")

    return 0;

}