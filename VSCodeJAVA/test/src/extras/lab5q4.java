package extras;
import java.util.Scanner;

public class lab5q4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean quit = false; 
        do{
            int a,b;
            int ch;
            System.out.println("Enter two numbers : ");
            a = sc.nextInt();
            b = sc.nextInt();
            System.out.println("1.Addition");
            System.out.println("2.Subtraction");
            System.out.println("3.Multiplication");
            System.out.println("4.Division");
            System.out.println("Choice:");
            ch = sc.nextInt();
            switch(ch){
                case 1:
                    System.out.println("Addition : "+ (a+b));
                    break;
                case 2:
                    System.out.println("Subtraction : "+ (a-b));
                    break;
                case 3:
                    System.out.println("Multiplication : "+ (a*b));
                    break;
                case 4:
                    System.out.println("Division : "+ (a/b));
                    break;
                
            }
            System.out.println("Do you want to continue?(1 for YES / 0 for NO)");
            ch = sc.nextInt();
            if(ch == 1)
                quit = true;
            else
                quit = false;

        }while(quit);
        sc.close();
    }
}
