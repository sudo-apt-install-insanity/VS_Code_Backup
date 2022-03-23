package lab7;

public class lab7q5 {
    public static double area(double radius)
    {
        if (radius < 0)
        {
            return -1;
        }
        return Math.PI * (radius * radius);
    }

    public static double area(double length, double breadth)
    {
        if (length < 0 || breadth < 0)
        {
            return -1;
        }
        double areaOfRectangle = length * breadth;        
        return areaOfRectangle;
    }

    public static double area(int a, double b, double c)
    {
        double temp = (a + b + c);
        double s= temp/2;
        double areaOfTriangle = Math.sqrt(s*(s-a)*(s-b)*(s-c));
        return areaOfTriangle;
    }
}
