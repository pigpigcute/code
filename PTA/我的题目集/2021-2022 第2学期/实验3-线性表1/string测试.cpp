#include<iostream>
#include<string>
using namespace std;

int main()
{
    string s[10];
    for(int i=0;i<10;i++)
    {
        cin>>s[i];
    }
    for(int i=0;i<10;i++)
    {
        cout<<s[i]<<endl;
    }
    return 0;
}