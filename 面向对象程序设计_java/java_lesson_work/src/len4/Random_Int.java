package len4;

public class Random_Int {
    public static void main(String[] args){
        int[] count = new int[10];
        int a;
        System.out.println("The digits are:");
        for(int i=0;i<10;i++){
            a=(int)(Math.random()*10);
            count[a]++;
            System.out.print(a+" ");
        }
        System.out.print("\n\n");
        System.out.println("The occurrences of each digit are:");
        for(int i=0;i<10;i++){
            System.out.println(i+" occurrence times is: "+count[i]);
        }
    }
}
