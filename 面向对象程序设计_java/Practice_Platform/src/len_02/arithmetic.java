package len_02;

import java.util.Scanner;

public class arithmetic {
    public static void main(String[] args) {
        /*********start*********/
        Scanner input = new Scanner(System.in);
        System.out.println("请输入第一个整数");
        int a = input.nextInt();
        System.out.println("请输入第二个整数");
        int b = input.nextInt();
        System.out.println("两数相加的结果为："+(a+b));
        System.out.println("两数相减的结果为："+(a-b));
        System.out.println("两数相乘的结果为："+(a*b));
        System.out.println("两数相除的结果为："+(a/b));
        System.out.println("两数取余数的结果为："+(a%b));
        /*********end*********/
    }
}
