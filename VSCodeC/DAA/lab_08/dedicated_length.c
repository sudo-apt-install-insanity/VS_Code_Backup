#include <stdio.h>   
void findBest(int dl, int m, int n) 
{ 
    int num_m = 0, num_n = 0, min_empty = dl; 
    int p = 0, q = 0, rem; 
    while (dl >= n) 
    { 
        q += 1; 
        dl = dl - n; 
        p = dl / m; 
        rem = dl % m;
        if (rem <= min_empty) 
        { 
            num_m = p; 
            num_n = q; 
            min_empty = rem; 
        } 
    } 
    printf("Number of m types : %d \nNumber of n types : %d \nWastage space : %d\n", num_m, num_n, min_empty); 
}  
int main() 
{ 
    int dl, m, n;
    printf("Enter the dedicated length : ");
    scanf("%d", &dl);
    printf("Enter the length of m and n type : ");
    scanf("%d %d", &m, &n);
    findBest(dl,m,n); 
    return 0; 
}