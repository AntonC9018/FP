// table inmultirii

#include <stdio.h>
#include <math.h>

int main()
{
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9; j++) {
            printf("%i * %i = %i\n", i, j, i * j);
        }
    }
}