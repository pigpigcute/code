//编写程序得出float和double类型的精度。

#include<stdio.h>
int main()
{
    float f =1.222222222222222222;
    double d =1.222222222222222222;
    printf("%.50f\n",f);
    printf("%.50f\n",d);
    return 0;
}