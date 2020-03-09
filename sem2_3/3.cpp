// n5
// 
// Avand data o matrice patratica A n x n
// sa se ordoneze elementele dupa ordinea crescatorea in mod de spirala

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
    int minReference = INT_MIN;
    int curentMin = INT_MAX;
    int currentMinCount = 0;
    int sortedElems[n * n]; 
    int i = 0;


    while (i < n * n) {   
        for (int j = 0; j < n * n; j++) {
            if(elems[j] > minReference) {
                if (elems[j] == curentMin) {
                    currentMinCount++;
                }

                else if (elems[j] < curentMin) {
                    currentMinCount = 1;
                    curentMin = elems[j];
                }
            }
        }
        for (int j = i; j < i + currentMinCount; j++) {
            sortedElems[j] = curentMin;
        }
        i += currentMinCount;
        minReference = curentMin;
        curentMin = INT_MAX;
        currentMinCount = 0;
    }

    puts("Elementele in ordinea crescatoare:");
    for (int i = 0; i < n * n; i++) {
        printf("%i ", sortedElems[i]);
    }

    // aranjam in spirala
    int sourceIndex = 0;

    int offsetX = 0;
    int offsetY = 0;

    while (offsetX < n / 2 && offsetY < n / 2) {

        for (int j = offsetX; j < n - offsetX - 1; j++) {
            A[offsetY][j] = sortedElems[sourceIndex++];
        }

        for (int i = offsetY; i < n - offsetY - 1; i++) {
            A[i][n - offsetX - 1] = sortedElems[sourceIndex++];
        } 

        for (int j = n - offsetX - 1; j > offsetX; j--) {
            A[n - offsetX - 1][j] = sortedElems[sourceIndex++];
        }

        for (int i = n - offsetY - 1; i > offsetY; i--) {
            A[i][offsetX] = sortedElems[sourceIndex++];
        }

        offsetX++;
        offsetY++;
    }

    if (n % 2 == 1) {
        A[n / 2][n / 2] = sortedElems[sourceIndex];
    }

    printf("\nTabloul final:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%5i", A[i][j]);
        printf("\n");
    }




    return 0;
}