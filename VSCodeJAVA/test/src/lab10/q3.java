package lab10;

interface inter {
    int x = 10;

    void disp();
}

class student implements inter {
    public void disp() {
        System.out.println(x);
    }

    public static void main(String[] args) {
        student obj = new student();
        obj.disp();
        // x=13;
        obj.disp();
    }
}