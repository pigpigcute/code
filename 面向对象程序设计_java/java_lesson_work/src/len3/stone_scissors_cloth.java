package len3;

import java.util.Scanner;

public class stone_scissors_cloth {
    public static void main(String[] args){
        Scanner input = new Scanner(System.in);
        int user,computer;
        while(true){
            System.out.print("scissor (0), rock (1), paper (2):");
            user = input.nextInt();
            if(user!=0&&user!=1&&user!=2){
                System.out.print("System out");
                break;
            }
            computer = (int)(Math.random()*3);
            switch(computer){
                case 0:
                    if(user==0) System.out.println("The computer is scissor. You are scissor too. It is a draw");
                    else if(user==1) System.out.println("The computer is scissor. You are rock. You won");
                    else if(user==2) System.out.println("The computer is scissor. You are paper. You lost");
                    break;
                case 1:
                    if(user==0) System.out.println("The computer is rock. You are scissor too. You lost");
                    else if(user==1) System.out.println("The computer is rock. You are rock. It is a draw");
                    else if(user==2) System.out.println("The computer is rock. You are paper. You won");
                    break;
                case 2:
                    if(user==0) System.out.println("The computer is paper. You are scissor too. You won");
                    else if(user==1) System.out.println("The computer is paper. You are rock. You lost");
                    else if(user==2) System.out.println("The computer is paper. You are paper. It is a draw");
                    break;
            }
        }
    }
}
