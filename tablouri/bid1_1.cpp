// a[i][j] = 2.3j + 5i
// de afisat
#include <stdio.h>
#include <math.h>

int main()
{
    int n, m;
    printf("Introduceti n, m: ");
    scanf("%i%i", &n, &m);

    float a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = 2.3 * j + 5 * i;

    // aflam cate cifre are elementul maxim
    // si adaugam 3 pentru doua cifre dupa punct si insusi punctul
    int size = log10(2.3 * m + 5 * n) + 1 + 3;

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%*.2f", size + 2, a[i][j]);
        printf("\n");
    }

    return 0;
}