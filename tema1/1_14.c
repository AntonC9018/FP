#include <stdio.h>
#include <math.h>

float a, b, x;


int main() 
{
    printf("Introduceti variabila a: ");
    scanf("%f", &a);
    printf("Introduceti variabila b: ");
    scanf("%f", &b);
    printf("Introduceti variabila x: ");
    scanf("%f", &x);

    float R = ((a * a * x) + exp(-x) * cos(b * x)) / (b * x - exp(-x) * sin(b * x) + 1);

    float s = exp(2 * x) * log(a + x) - pow(b, 3 * x) * log(b - x);

    printf("R = %f\n", R);
    printf("s = %f", s);

    return 0;
}
