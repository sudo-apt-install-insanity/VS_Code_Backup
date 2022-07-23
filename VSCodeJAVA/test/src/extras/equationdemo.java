package extras;
import java.util.Scanner;

public class equationdemo {
    public static void main(String[] args) {
        int a,b,c;
        Scanner sc = new Scanner(System.in);
        equation e = new equation();
        a = sc.nextInt();
        b = sc.nextInt();
        c = sc.nextInt();
        e.setCoeff(a, b, c);// 1,-5,6
        e.findRoots();
        System.out.println("r1 : "+e.r1 );
        System.out.println("r2 : "+e.r2 );
        sc.close();
    }
}
