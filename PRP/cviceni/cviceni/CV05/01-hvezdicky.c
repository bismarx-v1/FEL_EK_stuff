#include <stdio.h>

int n = 4;
char z = '$';
int main (void) {
    printf("{a}\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%c", z);
        }
        printf("\n");
    }


    printf("{b}\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            printf("%c", z);
        }
        printf("\n");
    }

    printf("{c}\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j<n; j++) {
            // if (j >= n-1 -i)
            printf("%c", (j >= n-1 -i)?z:' '); //ternarni operator, (podminka) ? TRUE:FALSE), ekvivalent if
            //     printf("%c", z);
            // else 
            //     printf(" ");
        }
        printf("\n");
    }

    printf("{d}\n");
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i; j++) {
            printf("%c", z);
        }
        printf("\n");
    }

   printf("{e}\n");
    for(int i = n -1; i >= 0; i--) {
        for(int j = 0; j<n; j++) {
            if (j >= n-1 -i)
                printf("%c", z);
            else 
                printf(" ");
        }
        printf("\n");
    }



return 0;

}