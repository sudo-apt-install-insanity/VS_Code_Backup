package lab10;

interface Income {
    double earnings();

    double deductions();

    double bonus();
}

abstract class Manager implements Income {
    double basic;

    public double earnings() {
        return basic + 0.8 * basic + 0.15 * basic;
    }

    public double deductions() {
        return 0.12 * basic;
    }
}

class Substaff extends Manager {
    Substaff(double base) {
        basic = base;
    }

    public double bonus() {
        return 0.5 * basic;
    }
}

public class q1 {
    public static void main(String[] args) {
        Substaff obj = new Substaff(2000.0);
        System.out.println("Earnings\tDeductions\tBonus");
        System.out.println(obj.earnings() + "\t\t" + obj.deductions() + "\t\t" + obj.bonus());
    }
}