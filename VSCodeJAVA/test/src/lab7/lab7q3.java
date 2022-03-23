package lab7;

public class lab7q3 {
    static String n = "Ainesh";
    static {
        System.out.println("Static block is intiliazied ");
    }

    static void setName() {
        n = "Akash";
    }

    void getName() {
        System.out.println(n);

    }

}