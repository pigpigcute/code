#include <iostream>
using namespace std;

int main()
{
    int t, n;
    int A[105], B[105];
    cin >> t;
    while (t--)
    {
        for(int i=0;i<105;i++)
        {
            B[i]=0;
        }
        cin >> n;
        for (int i = 1; i <= n; i++)
            cin >> A[i], B[A[i]]++;
        for (int i = 1; i <= 100; i++)
            if (B[A[i]] == 1)
            {
                cout << i << endl;
                break;
            }
    }
    return 0;
}