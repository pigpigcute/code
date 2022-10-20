#include <iostream>
#include <stdlib.h>
#define ElemType int
#define MaxSize 100
using namespace std;
typedef struct
{ //顺序表结构体
    ElemType data[MaxSize];
    int length;
} SqList;
void InitList(SqList &L)
{ //初始化线性表
    for (int i = 0; i < MaxSize; i++)
    {
        L.data[i] = 0;
    }
    L.length = 0;
}
void DisplayList(SqList L)
{ //输出顺序表中的数据
    cout << "顺序表中的数据有：" << endl;
    for (int i = 0; i < L.length; i++)
    {
        cout << L.data[i] << " ";
    }
    cout << endl;
}
void ListInsert(SqList &L, ElemType e, int i)
{ //插入一个数据到L中
    if (i < 0 || i > L.length + 1)
    {
        cout << "位置不合法！！" << endl;
        return;
    } //判断位置是否合法
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.data[j + 1] = L.data[j];
    }                  //元素后移
    L.data[i - 1] = e; //插入数据
    L.length++;        //长度加一
}
void ListDelete(SqList &L, int i)
{ //删除L中第i个数据
    if (i < 0 || i > L.length + 1)
    {
        cout << "位置不合法！！" << endl;
        return;
    } //判断位置是否合法
    for (int j = i - 1; j < L.length; j++)
    {
        L.data[j] = L.data[j + 1];
    }           //元素前移
    L.length--; //长度减一
}
void ListEmpty(SqList L)
{ //判断是否是空表
    int flag = 1;
    if (!L.length)
        flag = 0;
    if (flag)
        cout << "这不是一个空表！" << endl;
    else
        cout << "这是一个空表！" << endl;
}
void GetElem(SqList L, int i, ElemType &e)
{ //得到顺序表第i的值
    e = L.data[i - 1];
}
int LocateElem(SqList L, ElemType e)
{ //按元素查找某值,如果存在则返回序号，不存在则返回0
    for (int i = 0; i < L.length; i++)
    {
        if (L.data[i] == e)
            return i + 1;
    }
    return 0;
}
int ListLength(SqList L)
{ //返回线性表的长度
    return L.length;
}
void DestroyList(SqList L)
{ //销毁顺序表
    SqList *p = &L;
    free(p);
}
int main()
{
    SqList sl;
    ElemType e;
    InitList(sl); //初始化线性表
    int a[1000], n, i;
    cout << "请输入你要创建的顺序表长度：" << endl;
    cin >> n;
    cout << "请输入你要创建的顺序表数据：" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i]; //插入数据
        ListInsert(sl, a[i], i + 1);
    }
    DisplayList(sl); //数据显示
    cout << "请输入你要插入的数据:";
    cin >> e;
    cout << "请输入你要插入的位置:";
    cin >> i;
    ListInsert(sl, e, i);
    DisplayList(sl);
    cout << "请输入你要查询数据的位置:";
    cin >> i;
    GetElem(sl, i, e);
    cout << e << endl; // GetElem()函数的使用
    cout << "请输入你要查询的数据(存在则输出对应序号，不存在输出0)：";
    cin >> i;
    cout << LocateElem(sl, i) << endl; //查询数据
    // DestroyList(sl);
    cout << "请输入你要删除数据的位置:";
    cin >> i;
    ListDelete(sl, i);
    DisplayList(sl); //删除数据并显示
    return 0;
}
