// intoduce el matricei si le afiseaza sub forma de matrice
#include <stdio.h>
#include <math.h>

int main()
{
    int n, m;
    printf("Introduceti n, m: ");
    scanf("%i%i", &n, &m);

    float a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            printf("a[%i][%i] = ", i, j);
            scanf("%f", &a[i][j]);
        }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5.2f", a[i][j]);
        printf("\n");
    }

    return 0;
}
              