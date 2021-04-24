#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <time.h>
#include <stdlib.h>

int main() {

int y = 0;
int res;
printf("Вкажіть рік (1582-4902) ");
scanf("%i", &y);
    if (y<1582 || y>4902)
    {
        printf("Введіть рік від 1582 до 4902");
    }
    else
    {
        int m = 8;
        int d = 31;
        y = y%100;
        int c = y/100;
        for ( d; d > 1; d--)
        {
            res = 2.6*m - 0.2 + d + y + (y/4) + (c/4) - 2*c;
            res = res % 7;
            if (res ==0)
            {
                printf("october %i\n",d);
                break;
            }
        }
    }
}
