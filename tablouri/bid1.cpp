// a[i][j] = j * (i + j) + 5
// de afisat
#include <stdio.h>
#include <math.h>

int main() 
{
    int n, m;
    printf("Introduceti n, m: ");
    scanf("%i%i", &n, &m);

    int a[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            a[i][j] = j * (i + j) + 5;

    int size = log10(m * (n + m) + 5) + 1;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%*i", size + 1, a[i][j]);
        printf("\n");
    }

    return 0;
}
