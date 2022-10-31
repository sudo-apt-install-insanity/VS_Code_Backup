#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;  
} ll;

ll *head = NULL;
void printll()
{
    ll *temp;
    temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void create(int n)
{
    while (n > 0)
    {
        ll *temp = malloc(sizeof(ll));
        temp->data = rand() % 100;
        temp->next = head;
        head = temp;
        n--;
    }
    printll();
}
void bubbleSort(int n)
{
    ll *temp = head;
    while (temp != NULL)
    {
        ll *temp2 = temp->next;
        while (temp2 != NULL)
        {
            if (temp->data > temp2->data)
            {
                int t = temp->data;
                temp->data = temp2->data;
                temp2->data = t;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    temp = head;
    int k = n;
    while (k > 0)
    {
        if(k==n-1)
            printf("Second smallest : %d",temp->data);
        if(k==2)
            printf("\nSecond largest : %d",temp->data);
        temp = temp->next;
        k--;
    }

}
int main()
{
    srand(time(0));
    printf("Enter number of integers : ");
    int n;
    scanf("%d", &n);
    create(n);
    bubbleSort(n);
    return 0;
}
