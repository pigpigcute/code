package len4;

import java.util.Scanner;

public class Array_average {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter 10 double values:");
        double[] x=new double[10];
        double average;
        for(int i=0;i<10;i++){
            x[i]= input.nextDouble();
        }
        average=ave(x);
        System.out.print(average);
    }

    public static double ave(double[] array){
        double average,sum=0;
        for(int i=0;i<array.length;i++){
            sum=sum+array[i];
        }
        average=sum/array.length;
        return average;
    }
}

