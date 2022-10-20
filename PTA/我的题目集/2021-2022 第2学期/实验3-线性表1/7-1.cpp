#include <iostream>
using namespace std;

#define MAXSIZE 200 //������Ҫ�������Ա�Χ
#define ERROR -1
typedef int ElementType; //������Ϣ
typedef int Position;    //λ����Ϣ
typedef struct LNode *List;
struct LNode
{
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List MakeEmpty();                               //����һ���յ����Ա�
Position Find(List L, ElementType X);           //����X��λ�ã�û���򷵻�ERROR
void Insert(List L, ElementType X, Position P); //���룬��λ�ô��������������������false����ȷ�����򷵻�true

int main()
{
    List L;
    ElementType X;
    Position P;
    int N;
    L = MakeEmpty();
    int  m;
    cin>>N;
    for (int j = 0; j < N; j++)
    {
        cin >> X;
        Insert(L, X, j);
    }
    cin >> m;
    P=Find(L,m);
    if(P==-1){
        L->Data[L->Last+1]=m;
        L->Last++;
    }else{
        Insert(L,m,P);
    }
    for(int j=0;j<=L->Last;j++)
    {
        cout<<L->Data[j]<<",";
    }
    return 0;
}

List MakeEmpty() //����һ���յ����Ա�
{
    List L;
    L = (List)malloc(sizeof(struct LNode));
    L->Last = -1;
    return L;
}

Position Find(List L, ElementType X) //����X��λ�ã�û���򷵻�ERROR
{
    for (int i = 0; i <= L->Last; i++)
    {
        if (L->Data[i] > X)
            return i;
    }
    return ERROR;
}

void Insert(List L, ElementType X, Position P) //����
{
    for (int i = L->Last; i >= P; i--)
    {
        L->Data[i + 1] = L->Data[i];
    }
    L->Data[P] = X;
    L->Last++;
    return;
}
