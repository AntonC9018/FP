
#include <stdio.h>

void printTable(int *arr, int n, int m);
void scanTable(int *arr, int n, int m, const char *name);

void scanTable(int *arr, int n, int m, const char *name)
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%s[%i][%i] = ", name, i, j);
            scanf("%i", arr + i * n + j);
        }
    }
}

void printTable(int *arr, int n, int m) 
{
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            printf("%5i", *(arr + i * n + j));
        printf("\n");
    }
}

void printTable(float *arr, int n, int m);
void scanTable(float *arr, int n, int m, const char *name);

void scanTable(float *arr, int n, int m, const char *name)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%s[%i][%i] = ", name, i, j);
            scanf("%f", arr + i * n + j);
        }
    }
}

void printTable(float *arr, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%5f", *(arr + i * n + j));
        printf("\n");
    }
}