package extras;
import java.util.Scanner;

public class q3 {
    public static void main(String[] args) {
        int x = Integer.parseInt(args[0]);
        int y = Integer.parseInt(args[1]);
        System.out.println("Sum using CLI : "+(x+y));
        Scanner sc = new Scanner(System.in);
        x = sc.nextInt();
        y = sc.nextInt();
        System.out.println("Sum using Scanner : "+(x+y));
        sc.close();
    }
}
