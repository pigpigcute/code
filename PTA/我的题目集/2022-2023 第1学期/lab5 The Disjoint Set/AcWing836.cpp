/* 一
共有n个数，编号是1~n，最开始每个数各自在
一个集合中。现在要进行m个操作，操作共有两
种：“M a b”，将编号为a和b的两个数所在的
集合合并，如果两个数已经在同一个集合中，
则忽略这个操作；“Q a b”，询问编号为a和b
的两个数是否在同一个集合中； 
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
        if(op=='M') P[find(a)]=find(b); //合并
        else if(op=='Q') {
            if(find(a)==find(b)) cout<<"YES"<<endl;
            else cout<<"No"<<endl;
        }//查询
    }
}