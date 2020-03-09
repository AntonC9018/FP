#include <stdio.h>
#include <math.h>

float a, b, x;
float s;

int main() 
{
    puts("Introduceti variabile a, b, x:\n");
    scanf("%f%f%f", &a, &b, &x);

    if (x < 2.8) {
        s = (a + b) / (exp(x) + sin(x));
    } else if (x < 6) {
        s = (a + b) / (x + 1);
    } else {
        s = exp(x) + sin(x);
    }

    printf("s = %f", s);

    return 0;
}