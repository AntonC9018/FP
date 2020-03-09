#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c, z;
    printf("Introduceti variabile a, b, c, z:\n");
    scanf("%f%f%f%f", &a, &b, &c, &z);

    float max;
    float top[] = { a + b, b * b + c, 2 * a };

    if (top[0] > top[1] && top[0] > top[2])
        max = top[0];
    else if (top[1] > top[0] && top[1] > top[2])
        max = top[1];
    else
        max = top[2];

    float min;
    float bot[] = { 2 * b, 2 * z - 1, c };

    if (bot[0] < bot[1] && bot[0] < bot[2]) 
        min = bot[0];
    else if (bot[1] < bot[0] && bot[1] < bot[2])
        min = bot[1];
    else 
        min = bot[2];

    float y = max / min;   
    printf("y = %f", y);
    return 0;
}