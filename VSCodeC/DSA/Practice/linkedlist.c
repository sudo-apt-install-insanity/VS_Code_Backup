#include <stdio.h>
#include <stdlib.h>
typedef struct node *node;
node make_node(int);
void display(node);
struct node
{
    int data;
    node next;
};

node insert_front(node);
void insert_last(node);
int main()
{
    node head;
    head = (node)malloc(sizeof(node));
    head->next = NULL;
    printf("Enter first element :");
    scanf("%d", &head->data);
    int ch, ch1, flag = 1;

    while (flag)
    {
        printf("1.Add element.\n2.Remove element.\n3.Display element.\n4.Exit.\nEnter Choice : ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("1.Add at front.\n2.Add at last.\n3.Add at specified index.\nEnter Choice : ");
            scanf("%d", &ch1);
            switch (ch1)
            {
            case 1:
                head = insert_front(head);
                break;
            case 2:
                insert_last(head);
                break;
            case 3:

                break;

            default:
                printf("Invalid Choice!! Element not added..");
                break;
            }
            printf("\e[1;1H\e[2J");
            break;
        case 2:

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
node insert_front(node head)
{
    node temp;
    int data;
    printf("Enter element : ");
    scanf("%d", &data);
    temp = make_node(data);
    temp->next = head;
    head = temp;
    return head;
}
void insert_last(node head)
{
    node temp, last;
    int data;
    printf("Enter element : ");
    scanf("%d", &data);
    temp = make_node(data);
    last = head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = temp;
    temp->next = NULL;
}
void display(node curr)
{
    printf("Current elements in list : ");
    while (curr != NULL)
    {
        printf("%d ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}