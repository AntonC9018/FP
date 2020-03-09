// n41
// 
// Avand data o matrice patratica A n x n
// sa se ordoneze elementele dupa ordinea crescatorea in mod de:
//  a) sarpe
//  b) zigzag
//  c) spirala

#include <stdio.h>
#include <limits.h>

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

    // punem toate elementele intr-un vector
    int elems[n * n];

    // il umplem cu elementele lui A
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            elems[i + j * n] = A[i][j];
        }
    } 

    // sortam
    int currentLeast = INT_MIN;
    int min = INT_MAX;
    int leastCount = 0;
    int sortat[n * n]; 
    int i = 0;


    while (i < n * n) {   
        for (int j = 0; j < n * n; j++) {
            if(elems[j] > currentLeast) {
                if (elems[j] == min) {
                    leastCount++;
                }

                else if (elems[j] < min) {
                    leastCount = 1;
                    min = elems[j];
                }
            }
        }
        for (int j = i; j < i + leastCount; j++) {
            sortat[j] = min;
        }
        i += leastCount;
        currentLeast = min;
        min = INT_MAX;
        leastCount = 0;
    }

    puts("Elementele in ordinea crescatoare:");
    for (int i = 0; i < n * n; i++) {
        printf("%i ", sortat[i]);
    }

    // aranjam in spirala
    int sourceIndex = 0;

    int offsetX = 0;
    int offsetY = 0;

    while (offsetX < n / 2 && offsetY < n / 2) {

        for (int j = offsetX; j < n - offsetX - 1; j++) {
            A[offsetY][j] = sortat[sourceIndex++];
        }

        for (int i = offsetY; i < n - offsetY - 1; i++) {
            A[i][n - offsetX - 1] = sortat[sourceIndex++];
        }

        for (int j = n - offsetX - 1; j > offsetX; j--) {
            A[n - offsetX - 1][j] = sortat[sourceIndex++];
        }

        for (int i = n - offsetY - 1; i > offsetY; i--) {
            A[i][offsetX] = sortat[sourceIndex++];
        }

        offsetX++;
        offsetY++;
    }

    if (n % 2 == 1) {
        A[n / 2][n / 2] = sortat[sourceIndex];
    }

    printf("\nTabloul aranjat in mod de spirala:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%5i", A[i][j]);
        printf("\n");
    }


    sourceIndex = 0;

    // aranjam in mod de sarpe

    for (int i = 0; i < n; i += 2) {

        for (int j = 0; j < n; j++) {
            A[i][j] = sortat[sourceIndex++];
        }

        if (i + 1 < n) {
            for (int j = n - 1; j >= 0; j--) {
                A[i + 1][j] = sortat[sourceIndex++];
            }
        }
    }

    printf("\nTabloul aranjat in mod de sarpe:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%5i", A[i][j]);
        printf("\n");
    }


    // aranjam in mod de zigzag
    i = 0;
    int j = 0;
    int lowest = 0;
    int counter = 0;
    sourceIndex = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            A[i][j] = 0;
        }
    }
    A[i][j] = sortat[sourceIndex++];

    while (true) {
        
        // down one
        if (j == n - 1) {
            i++;
            lowest++;
        } else {
            j++;
        }

        if (lowest == n - 1)
            break;

        for (;j >= lowest; j--, i++) {
            A[i][j] = sortat[sourceIndex++];
        }
        i--;
        j++;


        if (i == n - 1) {
            j++;
            lowest++;
        } else {
            i++;
        }
        
        if (lowest == n - 1)
            break;

        for (;i >= lowest; i--, j++) {
            A[i][j] = sortat[sourceIndex++];
        }
        i++;
        j--;

    }

    A[n - 1][n - 1] = sortat[sourceIndex];

    printf("\nTabloul aranjat in mod de zigzag:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%5i", A[i][j]);
        printf("\n");
    }


    return 0;
}