package extras;
public class mynumber {
    int value;
    void setValue(int x){
        value = x;
    }
    boolean isEven(){
        if(value % 2 == 0)
            return true;
        else 
            return false;
    }
    int findFactorial(){
        int fact = 1;
        for(int i = 2; i <= value ; i++){
            fact *= i;
        }
        return fact;    
    }
    boolean isPrime(){
        boolean flag = true;
        for(int i = 2 ; i < Math.sqrt(value); i++){
            if(value % i == 0){
                flag = false;
                break;
            }   
        }
        return flag;
    }
    int sumOfDigits(){
        int sum = 0;
        int x = value;
        while(x != 0){
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }
}
