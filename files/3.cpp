// Să se determine soluţia ecuaţiei 
//      f(x) = e^x - x^2 
// pe segmentul
//      [-1, -0.5] 
// cu o precizie 
//      ε = 0.001
#include <stdio.h>
#include <math.h>

float f(float x)
{
    return exp(x) - x * x;
}

int main()
{
    float a, b, epsilon;
    printf("Metoda bisectiei\n");
    printf("a = ");
    scanf("%f", &a);
    printf("b = ");
    scanf("%f", &b);
    printf("Precizia = ");
    scanf("%f", &epsilon);
    int n = 0;
    float x, err1, err2;

    do
    {
        x = (a + b) / 2;
        if (f(a) * f(x) < 0)
            b = x;
        else
            a = x;
        
        // calculam erori
        err1 = fabs(f(x));
        err2 = x == 0 ? fabs(b - a) : fabs((b - a) / x);

        n++;

    } while (err1 > epsilon && err2 > epsilon);

    printf("\nx = %10.5f", x);
    printf("\nIteratii = %i", n);
    return 0;
}
