#include <iostream>
using namespace std;

int main()
{
    int t, n, m, a[100050];
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
    }

    return 0;
}
/* 

#include<iostream>
#include<cstdio>
#include<cstring>.
using namespace std;
int c[100005];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		memset(c,0,sizeof(c));
		int n,m,k;
		scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++){
			scanf("%d",&k);
			c[k%m]++;
		}
		int ans=!!(c[0]);
		for(int i=1;i<=m/2;i++){
			int a=max(c[i],c[m-i]),b=min(c[i],c[m-i]);
			if(c[i]==0&&c[m-i]==0) continue;
			if(a==b||a==b+1) ans+=1;
			else ans+=1+(a-b-1);
		}
		printf("%d\n",ans);
	}
	return 0;
}
*/