#include <stdio.h>
#include <math.h>

int main()
{
    float a, b;
    scanf("%f%f", &a, &b);
    float s;
    float x = 0;
    while (x <= 7) {
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
        x += 0.5f;
    }
    return 0;
}
