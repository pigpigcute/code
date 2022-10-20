// Problem: D. Permutation Transformation
// Contest: Codeforces - Codeforces Round #702 (Div. 3)
// URL: https://codeforces.ml/contest/1490/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// Powered by CP Editor (https://github.com/cpeditor/cpeditor)

#include <iostream>
using namespace std;
#define M 110
int T,n,a[M],FA[M],d[M];

void build(int l,int r,int fa)
{
	if(l>r) return;
	int MAXN=0,MAXI;
	for(int i=l;i<=r;i++)//第一处乱搞/ll
	{
		if(a[i]>MAXN)
		{
			MAXN=a[i];
			MAXI=i;
		}
	}
	FA[MAXN]=fa;
	build(l,MAXI-1,MAXN);
	build(MAXI+1,r,MAXN);
}

void dfs(int x,int D)
{
	d[x]=D;
	for(int i=1;i<=n;i++)//第二次乱搞
	{
		if(FA[i]==x)
		{
			dfs(i,D+1);
		}
	}
}

int main()
{
	cin>>T;
	for(int t=1;t<=T;t++)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		build(1,n,0);
		dfs(0,-1);
		for(int i=1;i<=n;i++)
		{
			cout<<d[a[i]]<<' ';//不是d[i]
		}
		cout<<endl;
	}
	return 0;
}