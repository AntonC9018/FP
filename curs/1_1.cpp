#include <stdio.h>
#include <string.h>

int main()
{
    char od[] = "Hello world";
    puts(od);
    strnset(od, ' ', 5);
    puts(od);
}