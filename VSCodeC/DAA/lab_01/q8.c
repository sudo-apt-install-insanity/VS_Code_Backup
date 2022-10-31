#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node
{
    int data;
    struct node *next;
} ll;
int product = 1;
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
        temp->data = rand() % 10;
        product *= temp->data;
        temp->next = head;
        head = temp;
        n--;
    }
    printll();
}
void prod_except_self()
{
    ll *temp = head;
    while (temp != NULL)
    {
        temp->data = product / temp->data;
        temp = temp->next;
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
    prod_except_self();
    return 0;
}
