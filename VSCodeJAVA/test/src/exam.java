import java.util.Scanner;

class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        boolean quit = false;

        while (!quit) {
            int n1 = sc.nextInt();
            int n2 = sc.nextInt();
            add(n1,n2);

        }
        sc.close();
    }

    static int add(int n1, int n2) {
        return n1 + n2;
    }

    static int subtract(int n1, int n2) {
        return n1 - n2;
    }

    static int multiply(int n1, int n2) {
        return n1 * n2;
    }
}