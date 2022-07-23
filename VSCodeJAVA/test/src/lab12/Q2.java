package lab12;


public class Q2 
{
    public static void main(String[] args) 
    {
        try
        {
            int x = 1/0;
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        catch(ArithmeticException e)
        {
            System.out.println(e);
        }   
    }   
}