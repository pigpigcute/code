#include <iostream>
using namespace std;

int main()
{
    int x1, y1, z1, x2, y2, z2, x, y, z;
    cin >> x1 >> y1 >> z1;
    cin >> x2 >> y2 >> z2;
    x = y1 * z2 - z1 * y2;
    y =-( x1 * z2 - x2 * z1);
    z = x1 * y2 - x2 * y1;
    cout << x << " " << y << " " << z;
}