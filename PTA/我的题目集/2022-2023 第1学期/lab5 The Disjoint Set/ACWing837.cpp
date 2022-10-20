/*
给定一个包含n个点（编号为1~n）的无向图，初
始时图中没有边。现在要进行m个操作，操作共有
三种：“C a b”，在点a和点b之间连一条边，a和
b可能相等；“Q1 a b”，询问点a和点b是否在同
一个连通块中，a和b可能相等；“Q2 a”，询问点
a所在连通块中点的数量；  
*/
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

const int N=1e5+10;

int n,m;
int p[N],size[N]; //p[N]存每个结点的父结点，size[N]存每个集合的元素个数
//只有祖宗结点的size才有意义 

int find(int x) //返回x的祖宗结点+路径优化 
{ 
	if(p[x]!=x) p[x]=find(p[x]); //p[x]!=x说明不是祖宗结点 
	return p[x];
}

int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		p[i]=i;    //刚开始每个元素都是各自在一个集合内，此时所有元素的p[x]=x 
		size[i]=1; // 刚开始每个集合都只有一个元素 
	}
	
	while(m--)
	{
		char op[5];
		int a,b;
		cin>>op;
		
		if(op[0] == 'C') //合并 
		{
			cin>>a>>b;
			if(find(a) == find(b)) continue; //a和b已经在一个集合了
			size[find(b)] += size[find(a)]; //合并后b(size)=b(size)+a(size)
			p[find(a)] = find(b); 
		}
		else if(op[1] == '1') //查询是否在同一集合 
		{
			cin>>a>>b;
			if(find(a) == find(b)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl; 
		}
		else //查询集合内元素个数
		{
			cin>>a;
			cout<<size[find(a)]<<endl;
		}
	}
	return 0;
}
