#include <iostream>
int main()
{
    int v[] = { -1, 2, -3, 4, 5, -6, 7 };
    int a = 0;
    int i;
    for (i = 0; i<= 6; i++) {
        if (a > v[i]) {
            a = v[i];
            v[i] = 0;
        }
        else 
            v[i]++;
    }
    for (int i = 0; i < 7; i++)
        std::cout << v[i];
}