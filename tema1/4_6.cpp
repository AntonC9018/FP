#include <stdio.h>
#include <math.h>

int main() 
{
    int x, y;
    char op;
    printf("Introduceti x, y si o operatie:\n");
    scanf("%i%i%c", &x, &y, &op);

    int result;
    if (op == '+') 
        result = x + y;
    else if (op == '-')
        result = x - y;
    else if (op == '*')
        result = x * y;
    else if (op == '/')
        result = x / y;
    else
        result = 0;

    printf("%i %c %i = %i", x, op, y, result);    
    return 0;
}   