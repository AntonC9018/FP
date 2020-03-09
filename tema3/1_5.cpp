// table inmultirii

#include <stdio.h>
#include <math.h>

int main()
{
    int width = 15, height = 100;
    int size = log10(width * height) + 2;

    printf("%*c", size, '*');
    for (int j = 1; j <= width; j++) {
        printf("%*i", size, j);
    }
    printf("\n");

    for (int i = 1; i <= height; i++) {
        printf("%*i", size, i);
        for (int j = 1; j <= width; j++) {
            printf("%*i", size, j * i);
        }
        printf("\n");
    }
}