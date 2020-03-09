#include <stdio.h>
#include <math.h>

int main()
{
    printf("Introduceti o litera: ");

    char ch;
    scanf("%c", &ch);

    printf("%d\n", ch);

    if (ch >= 'a') {
        ch -= 'z' - 'a' + 7;
    }

    if (ch > 'Z' || ch < 'A') {
        printf("Caracterul %c nu este o litera!", ch);
        return 0;
    }

    switch (ch)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
        printf("Litera %c este o vocala", ch);
        break;
    
    default:
        printf("Litera %c este o consoana", ch); 
        break;
    }
    return 0;    
}