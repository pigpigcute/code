#include <stdio.h>

#include <iostream>

using namespace std;

#define MAXSIZE 100

#define OK 1

#define ERROR 0

#define OVERFLOW -2

typedef struct
{

    int data[MAXSIZE];

    int length;

} SqList;

int InitList(SqList &L)

{

    L.length = 0;
    return OK;
}

void ShowList(SqList &L)

{

    cout << "您构建的顺序表为：" << endl;

    int i;

    for (i = 0; i < L.length; i++)

    {

        cout << L.data[i] << " ";
    }

    cout << endl;
}

void FindMax(SqList &L)

{

    cout << "该组数据的最大值为：" << endl;

    int m = L.data[0];

    int i;

    for (i = 0; i < L.length; i++)

    {

        if (m < L.data[i])

        {

            m = L.data[i];
        }
    }

    cout << m << endl;
}

int InsertList(SqList &L)
{

    int x, e;

    cout << "请问您要在第__个数字前插入新数字？";

    cin >> x;

    if (x < 1 || x > L.length)

    {

        cout << "该值错！" << endl;

        return ERROR;
    }

    if (L.length == MAXSIZE)

    {

        cout << "该顺序表空间已满，不能再添加数值！" << endl;

        return OVERFLOW;
    }

    cout << "您要插入的数字为：" << endl;

    cin >> e;

    for (int j = L.length - 1; j >= x - 1; j--)

        L.data[j + 1] = L.data[j];
    L.data[x - 1] = e;

    L.length++;

    cout << "插入新数字之后的顺序表为：" << endl;

    ShowList(L);

    return OK;
}

int DeleteElem(SqList &L)
{

    int x;

    cout << "请问您要删除第__个元素？";

    cin >> x;

    if (x < 1 || x > L.length)

    {

        cout << "该值错！" << endl;

        return ERROR;
    }

    for (int j = x - 1; j < L.length - 1; j++)

        L.data[j] = L.data[j + 1];

    L.length--;

    cout << "删除数字之后的顺序表为：" << endl;

    ShowList(L);

    return OK;
}

void UpRankList(SqList &L)

{

    int i, j, temp;

    for (j = 0; j < L.length - 1; j++)
    {

        for (i = 0; i < L.length - 1 - j; i++)

        {

            if (L.data[i] > L.data[i + 1])
            {

                temp = L.data[i];

                L.data[i] = L.data[i + 1];

                L.data[i + 1] = temp;
            }
        }
    }

    cout << "该数组按升序排列后为：" << endl;

    ShowList(L);
}

int main()

{

    SqList L;

    InitList(L);

    cout << "请输入要输入的数字的个数："
         << " ";

    cin >> L.length;

    cout << "请输入要输入的数字，并用空格隔开：" << endl;

    int i;

    for (i = 0; i < L.length; i++)

    {

        cin >> L.data[i];
    }

    cout << "请输入下列选项前的字母对该数组进行相应操作。" << endl

         << "A.显示出该顺序表" << endl

         << "B.找出该组数中的最大值" << endl

         << "C.在该顺序表中插入新数据" << endl

         << "D.删除某个数据" << endl

         << "E.将该顺序表按升序排列" << endl;

    char choice;

    do

    {

        cin >> choice;

        switch (choice)

        {

        case 'A':
            ShowList(L);
            break;

        case 'B':
            FindMax(L);
            break;

        case 'C':
            InsertList(L);
            break;

        case 'D':
            DeleteElem(L);
            break;

        case 'E':
            UpRankList(L);
            break;

        default:;
        }

    } while ((choice = 'A') && (choice = 'B') && (choice = 'C') && (choice = 'D') && (choice = 'E'));

    system("pause");

    return 0;
}
