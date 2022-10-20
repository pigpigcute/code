#include <stdio.h>
int a[10], book[10], n;
//这里还有需要注意的地方C语言全局变量默认为0

void dfs(int step)
{ //此时在第step盒子面前，需要往里面放第i张扑克牌
    int i;
    if (step == n + 1)
    { //这里说明前面的n个盒子已经放好了，这是dfs结束的标志
        for (i = 1; i <= n; i++)
            printf("%d", a[i]);
        printf("\n");

        return;
        /*
        注意这个 return 它的作用不是返回主函数，而是返回上一级的dfs函数

        例：如果此时是  dfs(5),遇到这个 return 就会回到上一级的 dfs函数
        也就是dfs(4),但此时dfs(4)的大部分语句已经执行了，只需要接着执行 book[i]=0
        然后继续进入for循环进入下一次的 dfs函数，直到结束。
        */
    }
    for (int i = 1; i <= n; i++)
    {
        if (book[i] == 0)
        {                //说明i号扑克牌还在手里，需要放入step号盒子
            a[step] = i; //将i号扑克牌放到第step个盒子中
            book[i] = 1; //此时i号扑克牌已经被使用
            dfs(step + 1);
            /*注意这里是自己调用自己，表示此时走到了第step+1个盒子面前*/
            book[i] = 0;
            /*book[i]=0表示dfs调用结束了，换句话说就是扑克牌已经全部放完了
              需要按照顺序将扑克牌收回，重新放，也就是前面所说的
             */
        }
    }
    return; //这里表示这一级别的dfs函数已经结束了，返回上一级 dfs函数
}
int main()
{
    scanf("%d", &n);
    dfs(1); // dfs函数的开始
    return 0;
}
