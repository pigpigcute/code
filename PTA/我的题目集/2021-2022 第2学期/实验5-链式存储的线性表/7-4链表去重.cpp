#include <iostream>
#include <cmath>
#include <set>
using namespace std;
const int maxx = 100000;

struct node
{
    int last;
    int data;
    int next;
} h[maxx];

int a[maxx], b[maxx], c[maxx];

int main()
{
    int n, m, k, r, r1, r2;
    cin >> n >> m;
    while (m--)
    {
        cin >> k;
        cin >> h[k].data >> h[k].next;
        h[k].last = k;
    }
    r = 0;
    r1 = 0;
    r2 = 0;
    while (n != -1)
    {
        a[r] = n;
        n = h[n].next;
        r++;
    }

    set<int> s;
    for (int i = 0; i < r; i++)
    {
        if (s.find(abs(h[a[i]].data)) == s.end())
        {
            b[r1] = a[i];
            r1++;
            s.insert(abs(h[a[i]].data));
        } //未找到重复，放入集合s
        else
        {
            c[r2] = a[i];
            r2++;
        }
    } //干湿分离

    /* for (int i = 0; i < r1 - 1; i++) //顺序输出去重后链表
    {
        cout << h[b[i]].last << " " << h[b[i]].data << " " << h[b[i + 1]].last << endl;
    }
    cout << h[b[r1 - 1]].last << " " << h[b[r1 - 1]].data << " "
         << "-1" << endl;

    for (int i = 0; i < r2 - 1; i++) //输出删除的数据
    {
        cout << h[c[i]].last << " " << h[c[i]].data << " " << h[c[i + 1]].last << endl;
    }
    cout << h[c[r2 - 1]].last << " " << h[c[r2 - 1]].data << " "
         << "-1" << endl;
 */
    for (int i = 0; i < r1 - 1; i++)
    {
        printf("%05d %d %05d\n", h[b[i]].last, h[b[i]].data, h[b[i + 1]].last);
    }
    printf("%05d %d -1\n", h[b[r1 - 1]].last, h[b[r1 - 1]].data);

    if (r2 > 0)
    {
        for (int i = 0; i < r2 - 1; i++)
        {
            printf("%05d %d %05d\n", h[c[i]].last, h[c[i]].data, h[c[i + 1]].last);
        }
        printf("%05d %d -1\n", h[c[r2 - 1]].last, h[c[r2 - 1]].data);
    }

    return 0;
}