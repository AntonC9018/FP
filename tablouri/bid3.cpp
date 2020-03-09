// Inroduce el matricei
// Afiseaza sub forma de matrice
// Calculeaza suma elementelor de pe fiecare coloana
#include <stdio.h>
#include <math.h>

int main()
{
    int n, m;
    printf("Introduceti n, m: ");
    scanf("%i%i", &n, &m);

    float a[n][m];
    float sums[m];
    for (int j = 0; j < m; j++)
        sums[j] = 0;
        
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%i][%i] = ", i, j);
            scanf("%f", &a[i][j]);
            sums[j] += a[i][j];
        }
    }
        

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%8.2f", a[i][j]);
        printf("\n");
    }

    for (int j = 0; j < m; j++) {
        printf("Suma elementelor %i coloane este %8.2f\n", j + 1, sums[j]);
    }

    return 0;
}