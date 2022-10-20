#include<iostream>
using namespace std;

int main()
{
    int t,n,m,c1,c2;
    cin>>t;
    while(t--)
    {
        cin>>n;
        c1=n/3;
        c2=c1;
        m=n%3;
        if(m==2) c2++;
        else if(m==1) c1++;
        cout<<c1<<" "<<c2<<endl;
    }
    return 0;
}