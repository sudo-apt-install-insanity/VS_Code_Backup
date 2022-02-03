public class q4 {
    public static void main(String[] args) {
        int n = Integer.parseInt(args[0]);
        int sumodd=0,sumeven=0;
        for (int i = 1; i <= n; i++) {
            if(Integer.parseInt(args[i]) % 2 == 0)
                sumeven += Integer.parseInt(args[i]);
            else    
                sumodd += Integer.parseInt(args[i]);
        }
        System.out.println("Even sum : " + sumeven);
        System.out.println("Odd sum : " + sumodd);
        System.out.println("Total sum : " + (sumeven+sumodd));
    }
}
