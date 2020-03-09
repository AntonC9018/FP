#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265f

int main() 
{
    float k;
    printf("Introduceti variabila k:\n");
    scanf("%f", &k);
    float WD;

    if (k < 1)
        WD = sin(2 / k);
    else if (k == 1)
        WD = 1 / k;
    else
        WD = abs(k * k) + PI;

    printf("WD = %f", WD);
    return 0;
}