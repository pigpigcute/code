#include<iostream>
using namespace std;

int main()
{
    int n,a[1010],t,m;
    cin>>a[1]>>a[2]>>n;
    cout<<a[1]<<" "<<a[2];
    while(n-2){
       t=a[1]*a[2];
       if(t<10){
           cout<<" "<<t;
           a[1]=a[2];
           a[2]=t;
            n--;
       }else{
           m=t%10;
           a[2]=m;
           m=t/10;
           a[1]=m;
           if(n-2>=2){
               cout<<" "<<a[1]<<" "<<a[2];
           }
           else if(n-2==1){
               cout<<" "<<a[1];
           }
           
           n=n-2;
       }
    }
    

    return 0;
}