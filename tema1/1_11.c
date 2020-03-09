#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float a, b, c, x;


int main() 
{
    printf("Introduceti variabila a, b, c, x:\n");
    scanf("%f%f%f%f", &a, &b, &c, &x);

    float y = log(a + x * x) + pow(sin(x / b), 2);

    float z = exp(-c * x) * (x + sqrt(x + a)) / (x - sqrt(abs(x - b)));

    printf("y = %f\n", y);
    printf("z = %f", z);

    return 0;
}
