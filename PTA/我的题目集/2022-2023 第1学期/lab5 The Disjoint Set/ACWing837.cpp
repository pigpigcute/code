/*
����һ������n���㣨���Ϊ1~n��������ͼ����
ʼʱͼ��û�бߡ�����Ҫ����m����������������
���֣���C a b�����ڵ�a�͵�b֮����һ���ߣ�a��
b������ȣ���Q1 a b����ѯ�ʵ�a�͵�b�Ƿ���ͬ
һ����ͨ���У�a��b������ȣ���Q2 a����ѯ�ʵ�
a������ͨ���е��������  
*/
#include<iostream>
using std::cout;
using std::cin;
using std::endl;

const int N=1e5+10;

int n,m;
int p[N],size[N]; //p[N]��ÿ�����ĸ���㣬size[N]��ÿ�����ϵ�Ԫ�ظ���
//ֻ�����ڽ���size�������� 

int find(int x) //����x�����ڽ��+·���Ż� 
{ 
	if(p[x]!=x) p[x]=find(p[x]); //p[x]!=x˵���������ڽ�� 
	return p[x];
}

int main()
{
	cin>>n>>m;
	for(int i=1; i<=n; i++)
	{
		p[i]=i;    //�տ�ʼÿ��Ԫ�ض��Ǹ�����һ�������ڣ���ʱ����Ԫ�ص�p[x]=x 
		size[i]=1; // �տ�ʼÿ�����϶�ֻ��һ��Ԫ�� 
	}
	
	while(m--)
	{
		char op[5];
		int a,b;
		cin>>op;
		
		if(op[0] == 'C') //�ϲ� 
		{
			cin>>a>>b;
			if(find(a) == find(b)) continue; //a��b�Ѿ���һ��������
			size[find(b)] += size[find(a)]; //�ϲ���b(size)=b(size)+a(size)
			p[find(a)] = find(b); 
		}
		else if(op[1] == '1') //��ѯ�Ƿ���ͬһ���� 
		{
			cin>>a>>b;
			if(find(a) == find(b)) cout<<"Yes"<<endl;
			else cout<<"No"<<endl; 
		}
		else //��ѯ������Ԫ�ظ���
		{
			cin>>a;
			cout<<size[find(a)]<<endl;
		}
	}
	return 0;
}
