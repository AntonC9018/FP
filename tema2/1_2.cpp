#include <stdio.h>
#include <math.h>

int main() 
{
    float b;
    scanf("%f", &b);
    float sum = 0;
    for (int i = 1; i <= 5; i++) {
        sum += i + 2.3f * b;
        printf("i = %i, Suma curenta = %f\n", i, sum);
    }
    printf("Suma = %f", sum);
    return 0;
}
