package lab6;

import java.util.*;
public class array2d
{
    public static void main(String args[])
    {
        Scanner sc=new Scanner (System.in);
        System.out.println("Enter the number of rows : ");
        int r=sc.nextInt();
        System.out.println("Enter the number of columns : ");
        int c=sc.nextInt();
        int arr[][]=new int[r][c];
        System.out.println("Enter the elements in the 2D array : ");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                arr[i][j]=sc.nextInt();
            }
        }
        System.out.println("The 2D array in matrix form is as below : ");
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                System.out.print(arr[i][j]+"\t");
            }
            System.out.println();
        }
        sc.close();
    }
}