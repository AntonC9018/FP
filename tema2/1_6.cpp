#include <stdio.h>
#include <math.h>
#include <conio.h>

int main() 
{
    for (char i = 'a'; i <= 'z'; i++) {
        for (int j = 'a'; j <= i; j++) {
            putch(j);
        }
        puts("");
    }
    return 0;
}