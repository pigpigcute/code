/* 
题目大概意思：处于迷宫入口的小明（1,1），寻找位于（p，q）的小红，也就是最短路径问题 其中n表示行，m表示列
*/
#include<stdio.h>
int book[51][51],a[51][51];
int n,m,p,q,min=99999;
	int next[4][2]={
 				    {0,1}, //向右走一步
					{1,0},//向下走一步
					{0,-1},//向左走一步
					{-1,0}};//向上走一步

void dfs(int x,int y,int step){   //step用来表示找到小红，小明走了多少步
	int tx,ty,k;
	if(x==p&& y==q){  //说明已经找到了小红  
	/*
	还要说明一点：这里 为什么是（x，y），而不是（tx，xy） 
	其实很简单 就是上一个dfs()函数传过来的坐标 ，做了这个dfs()函数的形参 
	换句话说：就是判断点是否找到小红 
	*/ 
		if(step<min)
			min=step;
		return ;   
		/*返回上一步，继续寻找其他路径（就是退回到上一个坐标，重新找其他路径）
		   回到上一个dfs()函数 
		
		*/ 
		}
		
	for(k=0;k<=3;k++){   //下一步的坐标
		tx=x+next[k][0]; 
		ty=y+next[k][1];
	
			//判断是否越界,越界则重新进入for循环 
			if(tx<1 || tx>n || ty<1 || ty>m)
				continue;  
				//运行到这里，说明这条路，则需要换个方向，也就是重新进入for循环
			if(a[tx][ty]==0 && book[tx][ty]==0){
				book[tx][ty]=1; //标记这个点走过
				dfs(tx,ty,step+1); //进行下一步
				book[tx][ty]=0;   //重新尝试，退回到上一个点的位置
		}
	
		}
		return ;   //执行到这里，这层dfs()函数已经结束，则要回到上一层dfs()函数 
	}

int main(){
	int i,j,startx,starty;
	scanf("%d %d",&n,&m);    //输入迷宫的大小 
	
	for(i=1;i<=n;i++)
		for(j=1;j<=m;j++)
			scanf("%d",&a[i][j]);  //输入迷宫的形状 
	
	scanf("%d %d",&startx,&starty);  //小明的坐标 
	scanf("%d %d",&p,&q);            //小红的坐标 
	
	book[startx][starty]=1;         //起始点标记，就不会回到这个点了 
	dfs(startx,starty,0);      //开始寻找最短路径 
	
	printf("%d",min);        //输出最短路径 
	return 0;
}
