package len8;

import java.util.Scanner;

public class three {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a, b, c: ");
        int a = input.nextInt(), b = input.nextInt(), c = input.nextInt();

        three_QuadraticEquation qe = new three_QuadraticEquation(a, b, c);

        double judge = qe.getDiscriminant();

        if (judge > 1){
            System.out.println("The roots are "+qe.getRoot1()+" and "+qe.getRoot2());
        } else if (judge < 0.0001 && judge > -0.0001){
            System.out.println("The root is "+qe.getRoot1());
        } else {
            System.out.println("The equation has no roots");
        }
    }
}
