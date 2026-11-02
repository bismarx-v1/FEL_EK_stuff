#include <stdio.h>

void printMonth(int daysInMonth, char dayInWeek)
{
    //dayinWeek
    printf("Mo Tu We Th Fr Sa Su\n");
    for (int d = 1; d <= daysInMonth; d++)
    {
        printf(" %2d, d");
        if( dayInWeek == 7) {   //sunday
            printf("\n");
        }
        else 
            dayInWeek ++;
    if (dayInWeek != 1) //
    printf("\n");
}

int main (void) 
{
    printMonth(31, 4);
    printMonth(30, 7);
    printMonth(31, 5);
    printMonth(31, 1);

    
    return 0;
    
}