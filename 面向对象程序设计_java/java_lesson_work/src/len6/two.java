package len6;

import java.util.Random;

public class two {
    public static void main(String[] args){
        Random generator1 = new Random(1000);
        for(int i=1;i<=50;i++){
            System.out.print(generator1.nextInt(100)+" ");
            if(i%10==0) System.out.println();
        }
    }
}
