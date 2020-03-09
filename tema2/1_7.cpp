#include <stdio.h>
#include <math.h>
#include <conio.h>

int main() 
{
    for (char i = 5; i >= 1; i--) {
        for (int j = 5 - i; j >= 0; j--) {
            putch(i + '0'); 
        }
        puts("");
    }
    return 0;
}