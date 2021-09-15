#include <stdio.h>
#include <stdlib.h>
typedef struct node *node;
node make_node(int);
void display(node);
node insert(node, int, int);
node delete (node, int);
node createLL(node );
int nodeCount(node );
struct node
{
    int data;
    node next;
};
int main()
{
    node head;
    head = (node)malloc(sizeof(node));
    head->next = NULL;
    int ch1;
    printf("1.Enter elements in bulk.(Size required)\n2.Enter singlular elements.\nEnter choice : ");
    scanf("%d", &ch1);
    switch (ch1)
    {
    case 1:
        head = createLL(head);
        break;
    case 2:
        printf("Enter first element :");
        scanf("%d", &head->data);
        break;

    default:
        printf("INvalid choice!Try again.");
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
            if (idx == 0)
                head = insert(head, idx, element_value);
            else
                insert(head, idx, element_value);

            printf("\e[1;1H\e[2J");
            break;
        case 2:
            display(head);
            printf("Enter index for removal : ");
            scanf("%d", &idx);
            if (idx == 1)
                head = delete (head, idx);
            else
                delete (head, idx);

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
node make_node(int value)
{
    node temp;
    temp = malloc(sizeof(node));
    temp->data = value;
    return temp;
}
node insert(node p, int idx, int value)
{
    node temp;
    if(idx < 0 || idx > nodeCount(p))
        return NULL;
    if (idx == 0)
    {
        temp = make_node(value);
        temp->next = p;
        p = temp;
        return p;
    }
    else if (idx > 0)
    {
        for (int i = 0; i < idx - 1 && p; i++)
            p = p->next;

        if (p)
        {
            temp = make_node(value);
            temp->next = p->next;
            p->next = temp;
        }
    }
}
node delete (node p, int idx)
{
    int i = 2;
    node q = NULL;
    if (idx == 1)
    {
        p = p->next;
        return p;
    }
    q = p;
    p = p->next;
    while (p)
    {
        if (idx == i)
        {
            q->next = p->next;
            p->next = NULL;
            free(p);
            return NULL;
        }
        q = p;
        p = p->next;
        i++;
    }
}
node createLL(node p){
    int *A,n;
    node temp,last;
    printf("Enter number of elements : ");
    scanf("%d",&n);
    A = (int*)malloc(sizeof(int)*n);
    printf("Enter elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d",A+i);
    }
    p->data = A[0];
    p->next = NULL;
    last = p;
    for (int i = 1; i < n; i++)
    {
        temp = make_node(A[i]);
        temp->next = NULL;
        last->next = temp;
        last = temp;  
    }
    return p;
}
void display(node curr){
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
int nodeCount(node p){
    int count = 0;
    while(p){
        count++;
        p = p->next;
    }
    return count;
}
