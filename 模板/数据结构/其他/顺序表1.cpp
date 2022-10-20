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

    cout << "��������˳���Ϊ��" << endl;

    int i;

    for (i = 0; i < L.length; i++)

    {

        cout << L.data[i] << " ";
    }

    cout << endl;
}

void FindMax(SqList &L)

{

    cout << "�������ݵ����ֵΪ��" << endl;

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

    cout << "������Ҫ�ڵ�__������ǰ���������֣�";

    cin >> x;

    if (x < 1 || x > L.length)

    {

        cout << "��ֵ��" << endl;

        return ERROR;
    }

    if (L.length == MAXSIZE)

    {

        cout << "��˳���ռ������������������ֵ��" << endl;

        return OVERFLOW;
    }

    cout << "��Ҫ���������Ϊ��" << endl;

    cin >> e;

    for (int j = L.length - 1; j >= x - 1; j--)

        L.data[j + 1] = L.data[j];
    L.data[x - 1] = e;

    L.length++;

    cout << "����������֮���˳���Ϊ��" << endl;

    ShowList(L);

    return OK;
}

int DeleteElem(SqList &L)
{

    int x;

    cout << "������Ҫɾ����__��Ԫ�أ�";

    cin >> x;

    if (x < 1 || x > L.length)

    {

        cout << "��ֵ��" << endl;

        return ERROR;
    }

    for (int j = x - 1; j < L.length - 1; j++)

        L.data[j] = L.data[j + 1];

    L.length--;

    cout << "ɾ������֮���˳���Ϊ��" << endl;

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

    cout << "�����鰴�������к�Ϊ��" << endl;

    ShowList(L);
}

int main()

{

    SqList L;

    InitList(L);

    cout << "������Ҫ��������ֵĸ�����"
         << " ";

    cin >> L.length;

    cout << "������Ҫ��������֣����ÿո������" << endl;

    int i;

    for (i = 0; i < L.length; i++)

    {

        cin >> L.data[i];
    }

    cout << "����������ѡ��ǰ����ĸ�Ը����������Ӧ������" << endl

         << "A.��ʾ����˳���" << endl

         << "B.�ҳ��������е����ֵ" << endl

         << "C.�ڸ�˳����в���������" << endl

         << "D.ɾ��ĳ������" << endl

         << "E.����˳�����������" << endl;

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
