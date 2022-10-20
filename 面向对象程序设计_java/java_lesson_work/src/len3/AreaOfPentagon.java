package len3;

import java.util.Scanner;

public class AreaOfPentagon {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the length from the center to a vertex:");
        double r = input.nextDouble();
        double Area,s;
        s=2*r*Math.sin(Math.PI/5);
        Area=(5*Math.pow(s,2))/(4*Math.tan(Math.PI/5));
        System.out.print("The area od the pentagon is "+Area);
    }
}
