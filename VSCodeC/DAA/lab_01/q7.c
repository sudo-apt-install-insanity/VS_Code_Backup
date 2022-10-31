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
    ll *temp=head;
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

void pair_swap()
{
    ll *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        int t = temp->data;
        temp->data = temp->next->data;
        temp->next->data = t;
        temp = temp->next->next;
    }
    printf("List after change : \n");
    printll();
}
int main()
{
    srand(time(0));
    printf("Enter number of integers : ");
    int n;
    scanf("%d", &n);
    create(n);
    pair_swap();
    return 0;
}
