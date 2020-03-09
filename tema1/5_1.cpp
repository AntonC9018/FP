#include <stdio.h>

int main()
{
    printf(
        "Obtine numarul de perechi pentru zi: \n\
1. Luni \n\
2. Marti \n\
3. Miercuri \n\
4. Joi \n\
5. Vineri \n\
6. Sambata \n\
7. Duminica \n\
");

    int t;
    scanf("%d", &t);

    switch (t)
    {
    case 1:
        printf("%s avem %d perechi", "Luni", 3);
        break;
    case 2:
        printf("%s avem %d perechi", "Marti", 4);
        break;
    case 3:
        printf("%s avem %d perechi", "Miercuri", 2);
        break;
    case 4:
        printf("%s avem %d perechi", "Joi", 4);
        break;
    case 5:
        printf("%s avem %d perechi", "Vineri", 3);
        break;
    case 6:
        printf("Sambata nu avem perechi");
        break;
    case 7:
        printf("Duminica nu avem perechi");
        break;
    default:
        printf("Saptamana are doar 7 zile! Nu exista a %d-a ziua!", t);
    }

    return 0;
}