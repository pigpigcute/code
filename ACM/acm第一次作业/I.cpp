#include <iostream>
using namespace std;

int main()
{
    int i, t, a[100], s, number = 0;
    double j, n;
    cin >> t;
    while (t--)
    {
        number = 0;
        s = 0;
        cin >> n;
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
            s = s + a[i];
        }

        if (s < 0)
        {
            cout << "1" << endl;
        }
        else
        {
            j = s / n;

            if (j == 1)
            {
                cout << "0" << endl;
            }
            else if (j > 1)
            {
                number = s - n;
                cout << number << endl;
            }
            else if (j < 1)
            {
                cout << "1" << endl;
            }
        }
    }
}