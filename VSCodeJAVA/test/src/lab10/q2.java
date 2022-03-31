package lab10;

interface motor {
    int capacity = 15;

    void run();

    void consume();
}

class washing_machine implements motor {
    public void run() {
        System.out.println("Inside run() Method");
    }

    public void consume() {
        System.out.println("Inside consume() method");
    }

}

public class q2 {
    public static void main(String[] args) {
        motor ob = new washing_machine();
        System.out.println("Value of capacity : " + motor.capacity);
        ob.run();
        ob.consume();
    }
}