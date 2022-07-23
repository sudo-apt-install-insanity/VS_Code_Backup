package extras;
import java.util.*;
public class circledemo {
    static public void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        circle c = new circle();
        c.radius = sc.nextInt();
        c.setDim(c.radius);
        c.findArea();
        c.perimeter();
        System.out.println("Diameter is : "+ c.diameter);
        System.out.println("Area is : "+ c.area);
        System.out.println("Perimeter is : "+ c.perimeter);
        sc.close();
    }
}
