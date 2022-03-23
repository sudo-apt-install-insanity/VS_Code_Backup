package lab6;

import java.lang.Math;
public class point
{
    int x,y;
    point()
    {
        x=3;
        y=4;
    }
    point(int a,int b)
    {
        x=a;
        y=b;
    }
    point(point o)
    {
        x=o.x;
        y=o.y;
    }
    void findDistance()
    {
        double dist = Math.sqrt(Math.pow(x,2)+Math.pow(y,2));
        System.out.println("Distance between points using default  : "+dist);
    }
    void findDistance(int x1,int y1)
    {
        double dist = Math.sqrt(Math.pow((x-x1),2)+Math.pow((y-y1),2));
        System.out.println("Distance between points using call by value: "+dist);
    }
    void findDistance(point o)
    {
        double dist = Math.sqrt(Math.pow((x-o.x),2)+Math.pow((y-o.y),2));
        System.out.println("Distance between points using object passing : "+dist);
    }
    void show()
    {
        System.out.println("\nx = "+x+"\ny = "+y);
    }
}