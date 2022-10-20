package len10;

public class Time {
    long hour,minute,second;
    long Millisecond;
    public Time(){
        Millisecond = System.currentTimeMillis();
        second=(Millisecond/1000)%60;
        minute=(Millisecond/60000)%60;
        hour=(Millisecond/3600000)%24;
    }

    public Time(long Millsecond){
        this.Millisecond = Millsecond;
        second=(Millisecond/1000)%60;
        minute=(Millisecond/60000)%60;
        hour=(Millisecond/3600000)%24;
    }

    private void rebulidMillisecond(){
        Millisecond = this.hour*3600000+this.minute*60000+this.second*1000;
    }

    public long getHour(){return hour;}
    public void setHour(long hour){
        this.hour=hour;
        rebulidMillisecond();
    }
    public long getMinute(){return minute;}
    public void setMinute(long Minute){
        this.minute = minute;
        rebulidMillisecond();
    }
    public long getSecond(){return second;}
    public void setSecond(long second){
        this.second = second;
        rebulidMillisecond();
    }

    public void setTime(long elapseTime){
        this.Millisecond=elapseTime;
        second=(Millisecond/1000)%60;
        minute=(Millisecond/60000)%60;
        hour=(Millisecond/3600000)%24;
    }
}
