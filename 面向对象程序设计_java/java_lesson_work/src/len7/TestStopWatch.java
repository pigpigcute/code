package len7;

import java.util.Arrays;

public class TestStopWatch {
    public static void main(String[] args){
        int[] a=new int[100000];
        for(int i=0;i<100000;i++){
            a[i]=(int)(Math.random()*100000+1);
        }
        int temp;
        StopWatch sw = new StopWatch();
        sw.start();
        for(int i=0;i<100000-1;i++){
            for(int j=i;j<100000;j++){
                if(a[i]>a[j]){
                    temp=a[i]; a[i]=a[j]; a[j]=temp;
                }
            }
        }
        sw.stop();
        System.out.println("选择: "+sw.getElapsedTime());

        for(int i=0;i<100000;i++){
            a[i]=(int)(Math.random()*100000+1);
        }
        sw.start();
        Arrays.sort(a);
        sw.stop();
        System.out.println("sort: "+sw.getElapsedTime());
    }
}
