//设计一个C语言程序，输出一个浮点数的IEEE754标准的二进制表示。


#include<stdio.h>

int main() {
    while (1) {
        float n, b;
        int flag = 0, two[100], o[100], ex[8] = {0}, a, i = 0, len = 0, point, k = 7;
        scanf("%f", &n);
        if (n == -1) break;
        if (n < 0) {
            flag = 1;
            n = -n;
        }
        int sum = flag;
        printf("Floating point value: %.9f\n", n);
        a = (int) n;
        b = n - (float )a;
        while (a) {
            two[i++] = a % 2;
            a /= 2;
            i++;
            len++;
        }
        point = len;
        for (i = 0; i < len; i++) o[i] = two[len - i - 1];
        for (i = len; i < 24; i++) {
            o[i] = (int) (b * 2);
            b = 2 * b - (int)(b * 2);
        }
        point = point - 1 + 127;
        while (point) {
            ex[k--] = point % 2;
            point /= 2;
        }

        for (i = 0; i < 8; i++) sum = sum*2 + ex[i];
        for (i = 1; i < 24; i++) sum = sum*2 + o[i];
        printf("Bit Representation 0x%x", sum);
        sum = 0;
        for (i = 0; i < 8; i++) sum = sum*2 + ex[i];
        printf("\tsign = %d  exponent = 0x%x", flag, sum);
        sum = 0;
        for (i = 1; i < 24; i++) sum = sum*2 + o[i];
        printf("\tfraction = 0x%x\n", sum);
    }
    return 0;
}
