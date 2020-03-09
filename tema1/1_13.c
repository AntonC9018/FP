#include <stdio.h>
#include <math.h>

float a, b, x;


int main() 
{
    printf("Introduceti variabila a, b, x:\n");
    scanf("%f%f%f", &a, &b, &x);

    float z = sqrt( a * x * sin(2 * x) + exp(-2 * x) * (x + b) );

    float w = pow(cos(pow(x, 3)), 2) - x / sqrt(a * a + b * b);

    printf("z = %f\n", z);
    printf("w = %f", w);

    return 0;
}
