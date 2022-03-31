package lab10;

interface Inter_1 {
    void disp();
}

class shape {
    void display() {
        System.out.println("The display function of shape class ");
    }
}

public class q6 extends shape implements Inter_1 {
    public void disp() {
        System.out.println("The display function of interface ");
    }

    public static void main(String[] args) {
        q6 obj = new q6();
        obj.disp();
        obj.display();
    }
}