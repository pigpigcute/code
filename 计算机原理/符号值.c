
//输出一个整数对应的有符号值和无符号值。

#include <stdio.h>

int Pow(int x, int n){
    int sum = 1;
    for (int i = 0; i < n; ++i) sum *= x;
    return sum;
}

int SumN(const char a[]){
    int b[200], sum = 0, k =0, len = 0;
    for (int i = 0; a[i] != '\0'; ++i) {
        if (a[i] >= '0' && a[i] <= '9') b[i] = a[i] - '0';
        else if(a[i] >= 'A' && a[i] <= 'F') b[i] = a[i] - 'A' + 10;
        len++;
    }
    for (int j = len-1; j >= 0; --j) sum +=  (int)(b[j] * Pow(16, k++));
    return (int)sum;
}

int main(){
    char num[20], q[11], hex[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    int a[20], pos, flag, sum, len;
    while(1){
        pos = flag = sum = len = 0;
        scanf("%s", num);
        if (num[0] == '.') break;
        if (num[0] == '0' && num[1] == 'x'){
            flag = 1;
            if (num[2] == '-'){
                pos = 1;
                for (int i = 0; num[i] != '\0'; ++i)
                    num[i] = num[i+3];
            }else
                for (int i = 0; num[i] != '\0'; ++i) num[i] = num[i+2];
        }
        if (num[0] == '-'){
            pos = 1;
            for (int i = 0; num[i] != '\0'; ++i) num[i] = num[i+1];
        }
        if (flag == 0){
            for (int i = 0; num[i] != '\0'; ++i) {
                a[i] = num[i] - '0';
                sum = sum*10 + a[i];
            }
        }
        if (flag == 1){
            for (int i = 0; num[i] != '\0'; ++i) len++;
            sum = SumN(num);
        }
        q[0] = '0', q[1] = 'x';
        for (int i = 2; i < 10; ++i) q[i] = '0';
        if (pos == 1) sum += 128;
        int t = sum, j = 9;
        while(t>0){
            q[j--] = hex[t%16];
            t /= 16;
        }
        if (pos == 0){
            printf("Hex:");
            for (int i = 0; i < 10; ++i) printf("%c", q[i]);
            printf("\tSinged: %d\tUnsigned: %d\n", sum, sum);
        }else{
            printf("Hex:");
            for (int i = 0; i < 9; ++i) printf("%c", q[i]);
            printf("\tSinged: %d\tUnsigned: %d\n", -sum, sum+128);
        }
    }
}
