#include <iostream>
using namespace std;

int main()
{
    int t;
    int a, b, n, s, number;
    cin >> t;
    while (t--)
    {
        cin >> a >> b >> n;
        number = 0;
        while (a <= n && b <= n)
        {
            if (a > b)
            {
                s = a;
                b = b + s;
            }
            else
            {
                s = b;
                a = a + s;
            }
            number++;
        }
        cout << number<<endl;
    }
    return 0;
}