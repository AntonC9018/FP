// n1 var9
// Se dau numerele reale s si t
// Calculati g(2s, 2t, 2.6) + g(28, 2.3, t) 

#include <stdio.h>

float g(float a, float b, float c);

int main() {
    float s, t;
    printf("Intorudceti s, t: ");
    scanf("%f%f", &s, &t);

    printf("Raspuns: %f", g(2 * s, 2 * t, 2.6f) + g(28.0f, 2.3f, t));

    return 0;
}

float g(float a, float b, float c) 
{
    return (b * b + 2 * c * c) / a; 
}