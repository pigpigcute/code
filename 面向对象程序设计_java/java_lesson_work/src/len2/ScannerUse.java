package len2;

import java.util.Scanner;

public class ScannerUse {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("请录入嫦娥个人信息：");
        System.out.print("请输入姓名：");
        String name = input.next();
        System.out.print("请输入年龄：");
        int age = input.nextInt();
        System.out.print("请输入性别：");
        String sex = input.next();
        System.out.print("请输入体重：");
        float wight = input.nextFloat();
        System.out.print("请输入地址：");
        String add = input.next();
        System.out.print("请输入是否已婚：");
        String y_n = input.next();
        System.out.println("信息如下：");
        System.out.println("\t姓名："+name);
        System.out.println("\t年龄："+age);
        System.out.println("\t性别："+sex);
        System.out.println("\t体重："+wight+"kg");
        System.out.println("\t地址："+add);
        System.out.println("\t婚否："+y_n);

    }
}
