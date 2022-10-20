#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n;
        if(n==1) cout<<"1"<<endl;
        else{
            m=pow(2,n);
            cout<<m-1<<endl;
        }
    }
    return 0;
}