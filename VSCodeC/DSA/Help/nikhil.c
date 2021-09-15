#include <stdio.h>
#include <stdlib.h>
int main(){
    int *a;
    a = malloc(5 * sizeof(int));

    for (int i = 0; i < 5; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Original array : ");
    for (int i = 0; i < 5; i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
    realloc(a,10*sizeof(int));
    printf("%d",sizeof(a));

    for (int i = 5; i < 10; i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Resized array : ");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ",a[i]);
    }

    
    
    
}