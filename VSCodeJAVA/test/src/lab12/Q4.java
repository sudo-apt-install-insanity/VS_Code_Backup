package lab12;

public class Q4 
{
    public static void main(String[] args) 
    {
        int arr[] = {1,2,3,4,5};
        System.out.println("The Array is : ");
        for(int i=0;i<5;i++)
        {
            System.out.print(arr[i]+" ");
        }
        System.out.println();
        try 
        {
            arr[6]=0;
        } 
        catch (ArrayIndexOutOfBoundsException e) 
        {
            System.out.println(e);
        }
        System.out.println("....End of Program...."); 
    }   
}
