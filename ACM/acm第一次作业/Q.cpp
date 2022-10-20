#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, q, t, k, a[100050], s;
    int x1 = 0, x0 = 0;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[1] == 0)
            x0++;
        if (a[i] == 1)
            x1++;
    }

    while (q--)
    {

        cin >> t >> k;
        if (t == 1)
        {
            a[k-1] = 1 - a[k-1];
            if (a[k-1] == 1)
            {
                x1++;
                x0--;
            }
            if (a[k-1] == 0)
            {
                x1--;
                x0++;
            }
        }
        if (t == 2)
        {
            if (k > x1)
                cout << "0" << endl;
            else
                cout << "1" << endl;
        }
    }
    return 0;
}