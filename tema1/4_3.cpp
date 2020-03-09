#include <stdio.h>
#include <math.h>

int main() 
{
    float a, b, c;
    printf("Introduceti variabile a, b, c:\n");
    scanf("%f%f%f", &a, &b, &c);

    if (a + b > 0) {

        // element minim
        if (a < b && a < c)
            printf("%6.2f, ", a);
        else if (b < a && b < c)
            printf("%6.2f, ", b);
        else
            printf("%6.2f, ", c);

        // element mediu
        if (a > b && a < c || a > c && a < b)
            printf("%6.2f, ", a);
        else if (b > a && b < c || b < a && b > c)
            printf("%6.2f, ", b);
        else
            printf("%6.2f, ", c);

        // element maxim
        if (a > b && a > c)
            printf("%6.2f", a);
        else if (b > a && b > c)
            printf("%6.2f", b);
        else
            printf("%6.2f", c);

    } else {
        if (b > c) 
            printf("%6.2f", b);
        else 
            printf("%6.2f", c);
    }
    return 0;
}