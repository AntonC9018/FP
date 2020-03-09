// table inmultirii

#include <stdio.h>
#include <math.h>

int main()
{
    printf("%3c", '*');
    for (int j = 1; j <= 9; j++) {
        printf("%3i", j);
    }
    printf("\n");

    for (int i = 1; i <= 9; i++) {
        printf("%3i", i);
        for (int j = 1; j <= 9; j++) {
            printf("%3i", j * i);
        }
        printf("\n");
    }
}
