#include <conio.h>
int main() 
{
    int n = 6;
    for (int i = 1; i <= 6; i++) {
        // if (n % i != 0 && i % 2 != 0)
        if (n % i && i % 2) {
            if (n - i) putch('A');
            else putch('B');
        }
        else putch('C');
    }
}