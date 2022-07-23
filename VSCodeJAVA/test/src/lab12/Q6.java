package lab12;

import java.util.*;

class Hours_Exception extends Exception 
{
    Hours_Exception(String s) 
    {
        super(s);
    }
}
class Minutes_Exception extends Exception 
{
    Minutes_Exception(String s) 
    {
        super(s);
    }
}
class Seconds_Exception extends Exception 
{
    Seconds_Exception(String s) 
    {
        super(s);
    }
}
class Time 
{
    int hrs, min, sec;

    Time(int hrs, int min, int sec)
    {
        this.hrs = hrs;
        this.min = min;
        this.sec = sec;
    }
    void display() throws Hours_Exception,Minutes_Exception,Seconds_Exception 
    {
        if (hrs < 0 || hrs > 24)
        {
            throw new Hours_Exception("Hours value is < 0 or > 24");
        }
        else
        {
            System.out.print(hrs + " hr ");
        }
        if (min < 0 || min > 60)
        {
            throw new Minutes_Exception("Minutes value is < 0 or > 60");
        }
        else
        {
            System.out.print(min + " min ");
        }
        if (sec < 0 || sec > 60)
        {
            throw new Seconds_Exception("Seconds value is < 0 or > 60");
        }
        else
        {
            System.out.print(sec + " sec");
        }
    }
}

public class Q6 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the hrs value : ");
        int hours = sc.nextInt();
        System.out.print("Enter the min value : ");
        int minutes = sc.nextInt();
        System.out.print("Enter the sec value : ");
        int seconds = sc.nextInt();
        sc.close();
        Time mytime = new Time(hours,minutes,seconds);
        try
        {
            System.out.print("\nThe Time is : ");
            mytime.display();
        } 
        catch(Hours_Exception e)
        {
            System.out.println(e);
        }
        catch(Minutes_Exception e)
        {
            System.out.println(e);
        }
        catch(Seconds_Exception e)
        {
            System.out.println(e);
        }
    }
}
