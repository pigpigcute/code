package len7;

import java.util.Date;

public class StopWatch {
    Date date1 = new Date();
    private long startTime,endTime;
    public StopWatch(){
        startTime=System.currentTimeMillis();
    }
    public void start(){
        this.startTime=System.currentTimeMillis();
    }
    public void stop(){
        this.endTime=System.currentTimeMillis();
    }
    public long getElapsedTime(){

        return this.endTime-this.startTime;
    }
}
