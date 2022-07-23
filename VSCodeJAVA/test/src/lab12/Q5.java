package lab12;

import java.util.*;
class NegativeNumberException extends Exception
{
    NegativeNumberException()
    {
        super();
    }
    public String toString() 
    {
        return "Output : User has entered a Negative number";
    }
}
public class Q5 
{
    static void processInput(int x)throws NegativeNumberException
    {
        if(x<0)
        {
            throw new NegativeNumberException();
        }
    }
    public static void main(String[] args) 
    {
        Scanner  s=new Scanner(System.in);
        System.out.print("Enter the number : ");
        int x =s.nextInt();
        try
        {
            processInput(x);
            System.out.println("Output : "+(double)(x*2));
        }
        catch(NegativeNumberException e)
        {
            System.out.println(e);
        }
        s.close();   
    }   
}
