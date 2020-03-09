#include <stdio.h>
#include <math.h>

int main()
{
    float b;
    scanf("%f", &b);

    float sum = 0;
    int i = 1;
    while (i <= 5) {
        sum += i + 2.3f * b;
        i++;
    }

    float product = 1;
    int k = 1;
    while (k <= 3) {
        product *= k;
        k++;
    }

    printf("f = %f", sum + product);
    return 0;
}

