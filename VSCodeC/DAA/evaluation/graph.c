#include <stdio.h>

int main(){
    int v,e;
    printf("Enter number of vertices :");
    scanf("%d",&v);
    printf("Enter number of edges :");
    scanf("%d",&e);

    int adj[v+1][v+1];

    for(int i = 0; i < e; i++){
        int from,to,weight;
        printf("Enter edge from :");
        scanf("%d",&from);
        printf("Enter edge to :");
        scanf("%d",&to);
        printf("Enter weight :");
        scanf("%d",&weight);
        adj[from][to] = adj[to][from] = weight;
    }

    for (int i = 0; i < v+1; i++)
    {
        for (int j = 0; j < v+1; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }
    

    return 0;

}