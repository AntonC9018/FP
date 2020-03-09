#include <iostream>
#include <cmath>
using namespace std;


bool isInside(float x, float y) {
    if (x >= 1 && x <= 2 && y >= 2 && y <= 4 
        && y >= x + 1 && y <= 2 * x)
        return true;

    float radSq = pow(x - 2, 2) + pow(y - 2, 2);
    if (x >= 2 && x <= 4 && y >= 2 && y <= 4 
        && radSq >= 1 * 1 && radSq <= 2 * 2)
        return true;

    if (x >= 2 && x <= 3 && y >= 1 && y <= 2
        && y < x - 1)
        return true;

    if (x >= 3 && x <= 4 && y >= 1 && y <= 2)
        return true;

    if (x >= 2 && x <= 4 && y >= -1 && y <= 1)
        return true;
    
    return false;
}

int main()
{
    float x, y;
    cin >> x >> y;

    if (isInside(x, y)) {
        cout << "Inside";
    } else {
        cout << "Not inside";
    }
    return 0;
}