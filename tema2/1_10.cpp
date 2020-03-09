#include <stdio.h>
#include <math.h>
#include <conio.h>

int main()
{
    for (char i = 0; i <= 5; i++) {
        for (int j = i; j > 0; j--) {
            putch(' ');
        }
        for (int j = 1; j <= 5 - i; j++) {
            putch(j + '0');
        }
        puts("");
    }
    return 0;
}