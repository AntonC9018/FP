#include <stdio.h>
int prim(int k, int L)
{
    int i, d = 0;
    for (i = 1; i < k && i < L; i++)
        if (k % i == 0 && k % i == 0)
            d++;

    if (d == 1)
        return 1;
    else
        return 0;
}

int main()
{
    int a, b, r, i;
    for (i = 1; i <= 5; i++)
    {
        printf("Introduceti parametrii: ");
        scanf("%i %i", &a, &b);
        r = prim(a,b);
        if (r == 1)
            printf("Perechea %i %i sunt reciproc prime\n", a, b);
        else
            printf("Perechea %i %i sunt reciproc prime\n", a, b);
    }

    return (0);
}