#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<string> q;
    q.push("first");
    q.push("second");
    cout << q.front() << endl;

    q.push("first");
    q.push("second");
    q.pop();
    cout << q.front() << endl;
    q.push("first");
    q.push("second");
    cout << q.size() << endl;
}