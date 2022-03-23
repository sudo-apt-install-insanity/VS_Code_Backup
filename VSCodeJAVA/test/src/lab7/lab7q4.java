package lab7;

public class lab7q4 {

    int c;
    void lab7q4 ()
    {
        c = 0;
    }
    void lab7q4 ( int a)
    {
        c = c + a;
    }
    void lab7q4 ( int a, int b)
    {
        System.out.println(c);
        System.out.println(c + "\t" + a + "\t" + b);
    }
public static void main(String[] args) {
    lab7q4 obj = new lab7q4();
    obj.lab7q4();
    obj.lab7q4(10);
    obj.lab7q4(20, 30);
}
}
