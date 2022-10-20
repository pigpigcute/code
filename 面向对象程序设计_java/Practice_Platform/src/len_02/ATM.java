package len_02;

import java.util.Scanner;

public class ATM {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int a,b,c;
        a=1000;
        System.out.println("欢迎使用中国人民银行ATM取款机");
        while(true){
            System.out.print("输入取款金额：");
            b=input.nextInt();
            if(b>a){
                System.out.println("目前余额:"+a+"无法满足您的取款需求！");
                continue;
            }
            else a=a-b;
            System.out.print("剩余金额："+a+"，是否继续（'1'：结束，'2'：继续）:");
            c=input.nextInt();
            if(c==1){
                System.out.print("取款结束！");
                break;
            }
        }
    }
}
