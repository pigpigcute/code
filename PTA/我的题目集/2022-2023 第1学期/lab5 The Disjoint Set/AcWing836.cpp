/* һ
����n�����������1~n���ʼÿ����������
һ�������С�����Ҫ����m������������������
�֣���M a b���������Ϊa��b�����������ڵ�
���Ϻϲ�������������Ѿ���ͬһ�������У�
����������������Q a b����ѯ�ʱ��Ϊa��b
���������Ƿ���ͬһ�������У� 
*/

#include<iostream>

using namespace std;

const int N=1e5+10;
int n,m;
int P[N];

int find(int x){
    if(P[x]!=x) P[x]=find(P[x]);
    return P[x];
}

int main(){
    char op;
    int a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++) P[i]=i;
    while(m--){
        cin>>op>>a>>b;
        if(op=='M') P[find(a)]=find(b); //�ϲ�
        else if(op=='Q') {
            if(find(a)==find(b)) cout<<"YES"<<endl;
            else cout<<"No"<<endl;
        }//��ѯ
    }
}