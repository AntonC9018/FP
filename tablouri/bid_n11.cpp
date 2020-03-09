// sa se considera tabloul A[n][m] de numere intregi, unde n,m <= 20.
// sa se scrie un program care transcrie in tabloul unidimensional B
// elementele pozitive din A
#include <stdio.h>
#include <math.h>

int main()
{
    int n, m;
    do {
        printf("Introduceti n, m: ");
        scanf("%i%i", &n, &m);
        if (n >= 20) {
            printf("n trebuie sa fie mai mic decat 20");
        }
        if (m >= 20) {
            printf("m trebuie sa fie mai mic decat 20");
        }
    } while(n >= 20 || m >= 20);

    int a[n][m];

    int b[n * m];
    int bIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%i][%i] = ", i, j);
            scanf("%i", &a[i][j]);
            if (a[i][j] > 0) {
                b[bIndex] = a[i][j];
                bIndex++;
            }
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5i", a[i][j]);
        printf("\n");
    }

    for (int i = 0; i < bIndex; i++)
        printf("\nb[%i] = %i", i, b[i]);

    return 0;
}

