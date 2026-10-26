#include <stdio.h>


int main (void) {
    int n = 10;
    for( int k = 0; k < n*n; k++) {

    printf("%3d", k );
    if (k % 10 == 9) //podminka odradkovani k % 10 == 9 - cislo konci 9
        printf("\n");
    }
        
return 0;

}