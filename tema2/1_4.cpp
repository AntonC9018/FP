#include <stdio.h>
#include <math.h>
#include <conio.h>

int main() 
{
    for (char i = 'z'; i >= 'a'; i--) {
        for (int j = 'z' - i; j >= 0; j--) {
            putch(i);
        }
    }
    return 0;
}