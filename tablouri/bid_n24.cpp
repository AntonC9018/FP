// sa se considera tabloul A[n][m] de numere intregi, unde n,m <= 20.
// sa se scrie un program care schimbe elementele din diagonal principala
// cu elementele din diagonala secundara 
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

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%i][%i] = ", i, j);
            scanf("%i", &a[i][j]);
        }
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5i", a[i][j]);
        printf("\n");
    }

    int minDim = n < m ? n : m;

    for (int i = 0; i < minDim; i++) {
        int temp = a[i][i];
        a[i][i] = a[i][m - i - 1];
        a[i][m - i - 1] = temp;
    }

    printf("\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5i", a[i][j]);
        printf("\n");
    }

    return 0;
}

