package lab10;

interface A {
    void math1();

    void math2();
}

interface B extends A {
    void math3();
}

class student implements B {
    // comment from here to label for error asked in question
    public void math1() {
        System.out.println("In function math1() ");
    }

    public void math2() {
        System.out.println("In function math2() ");
    }

    // label
    public void math3() {
        System.out.println("In function math3() ");
    }
}

public class q5 {
    public static void main(String[] args) {
        student obj = new student();
        obj.math1();
        obj.math2();
        obj.math3();
    }
}