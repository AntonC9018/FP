#include <stdio.h>
#include <math.h>

float a, b, t;
float w;

int main() 
{
    puts("Introduceti variabile a, b, t:\n");
    scanf("%f%f%f", &a, &b, &t);


    if (t < 0.1) {
        w = sqrt(a * t * t + b * sin(t) + 1);
    } else if (t > 0.1) {
        w = sqrt(a * t * t + b * cos(t) + 1);
    } else {
        w = a * t + b;
    }

    printf("W = %f", w);

    return 0;
}