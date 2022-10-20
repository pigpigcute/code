#include<iostream>
using namespace std;

const int N = 1e4+10;
int P[N];

int find(int x){
    if(P[x]<0) return x;
    else return P[x]=find(P[x]);
    
}

int main(){
    int n,root1,root2;
    cin>>n;
    for(int i=1;i<=n;i++){
        P[i]=-1;
    }
    char op;
    int a,b,number=0;
    cin>>op;
    while(op!='S'){
        cin>>a>>b;
        if(op=='C'){
            if(find(a)==find(b)) cout<<"yes"<<endl;
            else cout<<"no"<<endl;
        }
        //°´ÖÈÐòºÏ²¢
        else if(op=='I') {
            root1=find(a); root2=find(b);
            if(P[root1]>P[root2]){
                P[root1]=root2;
            }
            else if(P[a]<P[b]){
               
                P[root2]=root1;
            }
            else{
                P[root1]--;
                P[root2]=root1;
            }
        }
        cin>>op;
        if(op=='S') break;
    }

    for(int i=1;i<=n;i++){
        if(P[i]<0) number++;
    }
    if(number>1) cout<<"There are "<<number<<" components."<<endl;
    else cout<<"The network is connected."<<endl;
}