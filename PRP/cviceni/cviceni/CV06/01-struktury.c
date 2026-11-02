#include <stdio.h>

struct komplex {
    double re;
    double im;
};



typedef struct komplex komplex_t;
//podobne by dslo: typedef int cislo;

void tisk(struct komplex x) {
    printf("%.2f + %.2fj\n", x.re, x.im);
}


struct komplex soucet(struct komplex x, struct komplex y)
{
    struct komplex vysledek = {x.re + y.re, x.im + y.im};
    return vysledek;
}

struct komplex soucin(struct komplex x, struct komplex y)
{
    struct komplex vysledek;
    vysledek.re = x.re * y.re - x.im * y.im;
    vysledek.im = x.re * y.im + x.im * y.re;
    return vysledek;
}



int main() {

struct komplex a; //vytvorime neinicialozovanou strukturu

a.re = 3.1; //k prvkum pristupujme teckovou notaci 
a.im = 2.5;

struct komplex b = { -1.2, 2.1}; // inicializujeme vyctem, zalezi na poradi promennych
struct komplex c = {3.2, 0.0};
struct komplex d = {.im = 2.0}; //iniciualizujeme pouze im slozku
struct komplex e = {.im = 5.2, .re = -2.6}; // iniciualizujeme v jinem poradi

printf("a= %.2f + %.2fj\n", a.re, a.im);
printf("b= %.2f + %.2fj\n", b.re, b.im);
printf("c= %.2f + %.2fj\n", c.re, c.im);

printf("a="); tisk(a);
printf("b="); tisk(b);
printf("c="); tisk(c);
printf("d="); tisk(d);
printf("e="); tisk(e);

printf("a+b="); tisk(soucet(a, b));
printf("a*b="); tisk(soucin(a, b));


return 0;

}