package lab6;

import java.util.*;
public class pointdemo
{
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        // point obj = new point();
        System.out.println("Enter the position 1 : ");
        System.out.println("Enter the value x : ");
        int x1 = sc.nextInt();
        System.out.println("Enter the value y : ");
        int y1 = sc.nextInt();
        System.out.println("Enter the position 2 : ");
        System.out.println("Enter the value x : ");
        int x2 = sc.nextInt();
        System.out.println("Enter the value y : ");
        int y2 = sc.nextInt();
        point obj1 = new point (x1,y1);
        point obj2 = new point (x2,y2);
        obj1.show();
        obj2.show();
        obj1.findDistance();
        obj1.findDistance(x2,y2);
        obj1.findDistance(obj2);
        sc.close();
    }
}