/*
1-9 9个数凑一个等式，其中每个数由3个数字组成
*/
#include <stdio.h>
int a[10], book[10], total;
//这里还有需要注意的地方C语言全局变量默认为0

void dfs(int step)
{
    int i;
    if (step == 10)
    {
        if (a[1] * 100 + a[2] * 10 + a[3] + a[4] * 100 + a[5] * 10 + a[6] == a[7] * 100 + a[8] * 10 + a[9])
        {
            total++;
            printf("%d%d%d+%d%d%d=%d%d%d\n", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
        }
        return;
    }
    for (int i = 1; i <= 9; i++)
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
    dfs(1); // dfs函数的开始
    printf("%d", total / 2);
    return 0;
}
