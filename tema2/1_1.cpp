#include <stdio.h>
#include <math.h>

int main() 
{
    float a, b;
    scanf("%f%f", &a, &b);
    float s;
    for (float x = 0; x <= 7; x += 0.5f) {
        if (x < 2.8f) {
            s = (a + b) / (exp(x) + cos(x));
        }
        if (x >= 2.8f && x < 6.0f) {
            s = (a + b) / (x + 1);
        }
        if (x >= 6.0f) {
            s = exp(x) + sin(x);
        }
        printf("x = %f, s = %8.2f\n", x, s);
    }
    return 0;
}