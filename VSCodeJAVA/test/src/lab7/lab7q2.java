package lab7;

public class lab7q2 {
    static int st = 0;
    int nst = 0;

    lab7q2(){
        st++;
        nst++;
        System.out.println("Static : "+ st);
        System.out.println("Non-static : "+nst);
    }
    
}
