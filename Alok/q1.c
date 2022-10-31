#include<stdio.h>
#include<string.h>
int LCS(char s1[], char s2[], int m, int n)
{
  if(m==0||n==0)
  {
    return 0;
  }
  if(s1[m-1]==s2[n-1])
  {
    return 1 + LCS(s1,s2,m-1,n-1);
  }
  else 
  {
    return max(LCS(s1,s2,m,n-1),LCS(s1,s2,m-1,n));
  }
}
int max(int x, int y)
{

    if(x>y){
        return x;
    }else{
        return y;

    }
}

int main()
{
    char s1[]="HUMAN";
    char s2[]="CHIMPANZEE";
    int m= 6;
    int n= 10;
    int lc;
    lc=LCS(s1,s2,m,n);
    printf("The longest common subsequence is :- %d",lc);

}


