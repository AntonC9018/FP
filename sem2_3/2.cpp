// n6
// Se citeste o matrice A patratica
//
// a) de determinat toate elementele deasupra
//    diagonalei principale si cele de sub ea
//
// b) de determinat toate elementele deasupra
//    diagonalei secundare si cele de sub ea
//
// 1 2 3 4
// 5 6 7 8
// A B C D
// E F G H
//
// a) elementele deasupra d.p.:   2, 3, 4, 7, 8, D
//    elementele dedesubtul d.p.: 5, A, B, E, F, G
// b) elementele deasupra d.s.:   1, 2, 3, 5, 6, A
//    elementele dedesubtul d.s.: 8, C, D, F, G, H

#include <stdio.h>

int main() {
    int n;
    printf("Introduceti n: ");
    scanf("%i", &n);

    int A[n][n];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%i][%i] = ", i, j);
            scanf("%i", &A[i][j]);
        }
    }

    // afisam
    printf("Dimensiunele introduse: n = %i.\n\n", n);

    printf("Tabloul introdus A:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%5i", A[i][j]);
        printf("\n");
    }

    // diagonale
    printf("a) Elementele deasupra diagonalei principale: ");
    for (int i = 0; i <= n - 2; i++) {
        for (int j = i + 1; j < n; j++) {
            printf("%i, ", A[i][j]);
        }
    }

    printf("\n   Elementele dedesuptul diagonalei principale: ");
    for (int i = 1; i <= n - 1; i++) {
        for (int j = 0; j < i; j++) {
            printf("%i, ", A[i][j]);
        }
    }

    printf("\nb) Elementele deasupra diagonalei secundare: ");
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            printf("%i, ", A[i][j]);
        }
    }

    printf("\n   Elementele dedesuptul diagonalei secundare: ");
    for (int i = 1; i < n; i++) {
        for (int j = n - i; j < n; j++) {
            printf("%i, ", A[i][j]);
        }
    }


    

    return 0;
}