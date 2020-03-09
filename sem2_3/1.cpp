// n1
// Se citeste o matrice A patratica
// De obtinut o matrice B simetrica pe orizontala matricei A 
// fata de orizontala din mijlocul matricei
// 
// 1 2 3 4
// 5 6 7 8 
// A B C D
// E F G H
//
// E F G H
// A B C D
// 5 6 7 8
// 1 2 3 4

#include <stdio.h>

int main() {
    int n, m;
    printf("Introduceti n, m: ");
    scanf("%i%i", &n, &m);

    int A[n][m];
    int B[n][m];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("a[%i][%i] = ", i, j);
            scanf("%i", &A[i][j]);
        }
    }

    // aflam randul central
    // avem doua posibilitati: n este par si n este impar
    // daca n este impar, atunci nu schimbam randul cental
    // daca este par, atunci centrul este cam imaginar
    int topRow, botRow;
    
    // daca e par
    if (n % 2 == 0) {
        botRow = n / 2 - 1;
        topRow = n / 2;
    } else {
        botRow = n / 2 - 1;
        topRow = n / 2 + 1;

        // copiem centrul
        int center = n / 2;
        for (int i = 0; i < m; i++) {
            B[center][i] = A[center][i];
        }
    }

    // umplem B
    while(botRow >= 0 && topRow < n) {
        for (int i = 0; i < m; i++) {
            B[botRow][i] = A[topRow][i];
            B[topRow][i] = A[botRow][i];
        }
        botRow--;
        topRow++;
    } 

    // afisam
    printf("Dimensiunele introduse: n = %i, m = %i.\n\n");

    printf("Tabloul introdus A:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5i", A[i][j]);
        printf("\n");
    }

    printf("\nTabloul procesat B:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5i", B[i][j]);
        printf("\n");
    }

    return 0;
}