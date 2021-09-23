#include <stdio.h>
#include <stdlib.h>
struct id{
    char username[20];
    char password[20];
};
int main(){
    FILE *fp;
    fp = fopen("ids.csv","a+");
    int query;

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            fprintf(fp,"%d,",i*j);
        }
        fprintf(fp,"\n");
    }


    // printf("Enter number to search : ");
    // scanf("%d",&query);
    // int temp;
    // while(fread(&temp,sizeof(int),1,fp)){
    //     if(temp == query)
    //         printf("Found in file!!\n");
    //     else
    //         printf("Not found in file!!\n");
        
    // }

    fclose(fp);
    
}