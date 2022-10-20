#include <iostream>
#include <iomanip>
using namespace std;
struct bk
{
    char number[200];
    char name[200];
    double price;
} book[1000];
int main()
{
    int n = 0, i;
    while (1)
    {
        cin >> book[n].number;
        cin >> book[n].name;
        cin >> book[n].price;
        if (book[n].number[0] == '0' && book[n].name[0] == '0' && book[n].price == 0)
        {
            break;
        }
        n++;
    }
    cout << n << endl;
    for (i = 0; i < n; i++)
    {
        cout << book[i].number << " " << book[i].name << " " << fixed << setprecision(2) << book[i].price << endl;
    }
}

//运行出错
/*#include <iostream>
#include <string>
#include <iomanip>
#include<cstdlib>
using namespace std;

#define MAXSIZE 200 //根据需要调整线性表范围
#define ERROR -1
typedef int ElementType; //数据信息
typedef int Position;    //位置信息
typedef struct LNode *List;
struct LNode
{
    string number[MAXSIZE];
    string name[MAXSIZE];
    float price[MAXSIZE];
    Position Last; // 保存线性表中最后一个元素的位置
};

List MakeEmpty(); //创建一个空的线性表
void Insert(List L, string s, string n, float t, Position P);
void outset(List L);

int main()
{
    List L;
    L = MakeEmpty();
    string m1, n1, m0 = "0", n0 = "0";
    float t1, t0 = 0;
    int i = 0;

    while (1)
    {
        cin >> m1 >> n1 >> t1;
        if (m1 == m0 && n1 == n0 && t1 == t0)
            break;
        Insert(L, m1, n1, t1, i);
        i++;
    }

    return 0;
}

void outset(List L)
{
    cout << L->Last << endl;
    for (int i = 0; i <= L->Last; i++)
    {
        cout << L->number << " " << L->name << " " << setprecision(4) << L->price << endl;
    }
}

List MakeEmpty() //创建一个空的线性表
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

void Insert(List L, string s, string n, float t, Position P) //插入
{
    for (int i = L->Last; i >= P; i--)
    {
        L->number[i] = L->number[i + 1];
        L->name[i] = L->name[i + 1];
        L->price[i] = L->price[i + 1];
    }
    L->number[P] = s;
    L->name[P] = n;
    L->price[P] = t;
    L->Last++;
    return;
}
*/
