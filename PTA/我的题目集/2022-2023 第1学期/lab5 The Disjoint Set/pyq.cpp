#include<iostream>
using namespace std;

const int X=30010;
int n,m;
int P[X];

int find(int x){
    if(P[x]<=0) return x;
    else return P[x]=find(P[x]);
}

int main(){
    cin>>n>>m;
    int i,t,t1,t2;
    int root1,root2;
    for(i=1;i<=n;i++) P[i]=-1;
    while(m--){
        cin>>t;//输入该俱乐部人数
        cin>>t1;
        root1=find(t1);
        t--;
        while(t--){
            cin>>t2;
            root2=find(t2);
            if(root1!=root2){
                P[root1]+=P[root2];
                P[t2]=root1;
            }
        }
    }
    int maxx=1;
    for(i=2;i<=n;i++){
        if(P[i]<P[maxx]) maxx=i;
    }
    cout<<-P[maxx]<<endl;
}