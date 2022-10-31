#include <stdio.h>
#include <stdlib.h>
typedef struct node node;
struct node
{
    int data;
    node *next;
};
node *make_node(int);
void display(node *);
void insert(node **, int, int);
void Delete(node **, int);
void createLL(node **);
int nodeCount(node *);

int main()
{
    node *head = NULL;
    // head = (node *)malloc(sizeof(struct Node));
    // head->next = NULL;
    // node *head_ref;
    // head_ref = head;
    int ch1;
    printf("1.Enter elements in bulk.(Size required)\n2.Enter singlular elements.\nEnter choice : ");
    scanf("%d", &ch1);
    switch (ch1)
    {
    case 1:
        createLL(&head);
        break;
    case 2:
        printf("Enter first element :");
        scanf("%d", &head->data);
        break;

    default:
        printf("Invalid choice!Try again.");
        break;
    }

    int ch, flag = 1;

    while (flag)
    {
        printf("1.Add element.\n2.Remove element.\n3.Display elements.\n4.Exit.\nEnter Choice : ");
        scanf("%d", &ch);
        int idx, element_value;
        switch (ch)
        {
        case 1:
            display(head);
            printf("Enter index for insertion(0 for inserting at front) : ");
            scanf("%d", &idx);
            printf("Enter value for insertion : ");
            scanf("%d", &element_value);
            insert(&head, idx, element_value);
            printf("\e[1;1H\e[2J");
            break;
        case 2:
            display(head);
            printf("Enter index for removal : ");
            scanf("%d", &idx);
            Delete(&head, idx);
            // printf("\e[1;1H\e[2J");
            break;
        case 3:
            display(head);
            break;
        case 4:
            flag = 0;
            break;

        default:
            printf("Invalid Choice!!Try Again.");
            break;
        }
    }
}
node *make_node(int value)
{
    node *temp;
    temp = (node *)malloc(sizeof(node));
    temp->data = value;
    return temp;
}
void insert(node **p, int idx, int value)
{
    node *temp;
    if (idx < 0 || idx > nodeCount(*p))
        return;
    if (idx == 0)
    {
        temp = make_node(value);
        temp->next = *p;
        *p = temp;
    }
    else if (idx > 0)
    {
        for (int i = 0; i < idx - 1 && p; i++)
            *p = (*p)->next;

        if (*p)
        {
            temp = make_node(value);
            temp->next = (*p)->next;
            (*p)->next = temp;
        }
    }
}
void Delete(node **p, int idx)
{
    node *t = *p;
    node *q = NULL;
    if (idx == 1)
    {
        t = *p;
        (*p) = (*p)->next;
        return;
    }
    // q = t;
    // t = t->next;
    int i = 1;
    while (t)
    {
        if (idx == i)
        {
            q->next = t->next;
            t->next = NULL;
            free(t);
            return;
        }
        q = t;
        t = t->next;
        i++;
    }
}
void createLL(node **p)
{
    int *A, n;
    node *temp, *last;
    printf("Enter number of elements : ");
    scanf("%d", &n);
    A = (int *)malloc(sizeof(int) * n);
    printf("Enter elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", A + i);
    }
    *p = (node *)malloc(sizeof(struct node));
    (*p)->data = A[0];
    (*p)->next = NULL;
    last = *p;
    for (int i = 1; i < n; i++)
    {
        temp = make_node(A[i]);
        temp->next = NULL;
        last->next = temp;
        last = temp;
    }
}
void display(node *curr)
{
    printf("Current elements in list : \n");
    int i = 1;
    if (!curr)
        printf("EMPTY.\n");
    while (curr != NULL)
    {
        printf("Element[%d] - %d ", i, curr->data);
        curr = curr->next;
        i++;
        printf("\n");
    }
}
int nodeCount(node *p)
{
    int count = 0;
    while (p)
    {
        count++;
        p = p->next;
    }
    return count;
}