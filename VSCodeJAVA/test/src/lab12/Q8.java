package lab12;

public class Q8
{
    public static void main(String[] args) 
    { 
        try
        { 
            System.out.println(10/0);            
        }  
        catch(ArithmeticException e)
        { 
           System.out.println(e);
        }  
        finally
        {
            System.out.println("Inside finally block");
        }  
        System.out.println("....End of the program....");  
    }  
}