package extras;
public class mynumberdemo {
    public static void main(String[] args) {
        mynumber m = new mynumber();
        m.setValue(10);
        
        System.out.println("Even : " + m.isEven());
        System.out.println("Prime : " + m.isPrime());
        System.out.println("Sum of digits : " + m.sumOfDigits());
        System.out.println("Factorial : " + m.findFactorial());

    }
}

