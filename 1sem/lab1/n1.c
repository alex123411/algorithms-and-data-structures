#include <stdio.h>
#include <math.h>

int main() {

float a = 0;
float b = 0;
float x = 0;
float y = 0;
float z = 0;

printf("x = ");
scanf("%f", &x);
printf("y = ");
scanf("%f", &y);
printf("z = ");
scanf("%f", &z);

    if (x == 2) {
    printf("Значення введені неправильно\n");
    }
    else if (x == -2) {
    printf("Значення введені неправильно\n");
    }
    else {
    a = (1 + y) * (((x + y/(pow(x,2)+4)) / (pow(z,-x-2)+(1/(pow(x,2)-4)))));
    b =  (1 + pow(cos(a-2),y)) / (pow(x,4)/2-pow(sin(z),2));
    printf("a = %f\n",a);
    printf("b = %f",b);

    }
}
