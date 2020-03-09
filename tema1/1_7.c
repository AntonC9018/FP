#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float a, b, x;


int main() 
{
    printf("Introduceti variabila a, b, x:\n");
    scanf("%f%f%f", &a, &b, &x);

    float R = x * x * (x + 1) / b - pow(sin(x + a), 2);

    float s = sqrt(x * b / a) + pow(cos(pow(x + b, 3)), 2);

    printf("R = %f\n", R);
    printf("s = %f", s);

    return 0;
}
