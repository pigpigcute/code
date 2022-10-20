#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    double x[2010],y[2010],res;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%lf%lf",&x[i],&y[i]);
    }
    res=1/(double)n;
    printf("%.15lf",res);

}