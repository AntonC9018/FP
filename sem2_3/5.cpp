// n46
// De calculat determinantul unei matrice[n][m]

#include <stdio.h>

int m, n;

int det(int* arr, int* rows, int rowCount, int x);
int calcDet(int* arr);


int calcDet(int* arr) 
{
    int startRows[m];
    for (int i = 0; i < m; i++) {
        startRows[i] = i;
    }
    return det(arr, startRows, m, 0);
}



int det(int* arr, int* rows, int rowCount, int x) 
{
    if (x == n - 2) {
        return arr[rows[0] * n + x] * arr[rows[1] * n + x + 1] 
            - arr[rows[0] * n + x + 1] * arr[rows[1] * n + x]; 
    }

    int sum = 0;
    int sign = 1;
    for (int r = 0; r < rowCount; r++) {
        int rowArrForRecursion[rowCount - 1];
        int rowCounter = 0;
        for (int nextRow = 0; nextRow < rowCount; nextRow++) {
            if (nextRow != r) {
                rowArrForRecursion[rowCounter++] = rows[nextRow];
            }
        }
        sum += arr[rows[r] * n + x] * sign * det(arr, rowArrForRecursion, rowCount - 1, x + 1);
        sign *= -1;
    }

    return sum;
}


int main() 
{
    printf("Introduceti m, n: ");
    scanf("%i%i", &m, &n);

    if (n != m) {
        puts("Determinatul nu este definit pentru matricile care nu sunt patratice");
        return 0;
    }

    int A[m][n];

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("a[%i][%i] = ", i, j);
            scanf("%i", &A[i][j]);
        }
    }

    printf("Tabloul introdus A:\n");

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            printf("%5i", A[i][j]);
        printf("\n");
    }


    printf("Determinantul = %i", calcDet(A[0]));

    return 0;
}