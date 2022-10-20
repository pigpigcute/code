#include<bits/stdc++.h>
using namespace std;

const int N = 10001;
int P[N];

int find(int x){
    if(P[x]!=x) P[x]=find(P[x]);
    return P[x];
}

struct node
{
    /* data */
    int x,y,weight;
}S[N];

bool wcp(node a,node b){
    return a.weight<b.weight;
}

int main(){
    int n,m,t=1,sum=0;
    cin>>n;
    for(int i=1;i<=n;i++){P[i]=i;}
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++){
            S[t].x=i;
            S[t].y=j;
            cin>>S[t].weight;
            t++;
        }
    cin>>m;
    int a,b;
    while(m--){
        cin>>a>>b;
        P[find(a)]=P[find(b)];
    }

    sort(S,S+t,wcp);

    for(int i=1;i<=t;i++){
        if(find(S[i].x)!=find(S[i].y)){
            P[find(S[i].x)]=S[i].y;
            sum+=S[i].weight;
        }
    }
    cout<<sum<<endl;
    return 0;
}