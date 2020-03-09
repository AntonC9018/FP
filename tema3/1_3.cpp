#include <stdio.h>
#include <math.h>

int main()
{
    float b;
    scanf("%f", &b);

    float sum = 0;
    int i = 1;
    
    do {
        sum += i + 2.3f * b;
        i++;
    } while (i <= 5);

    float product = 1;
    int k = 1;
    
    do {
        product *= k;
        k++;
    } while (k <= 3);

    printf("f = %f", sum + product);
    return 0;
}