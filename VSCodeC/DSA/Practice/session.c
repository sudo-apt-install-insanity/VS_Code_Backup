#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
//-------------------------------------------------// 
struct Stack {
    int top;
    unsigned capacity;
    int* array;
};
struct Stack* st;

struct Stack* createStack(unsigned capacity)
{
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}
int isFull()
{
    return st->top == st->capacity - 1;
}
 

int isEmpty()
{
    return st->top == -1;
}
void push(int val)
{
    if (isFull())
        return;
    st->array[++st->top] = val;
    // printf("%d pushed to st\n", val);
}
 
int pop()
{
    if (isEmpty())
        return INT_MIN;
    return st->array[st->top--];
}
 
int peek()
{
    if (isEmpty())
        return INT_MIN;
    return st->array[st->top];
}

//--------------------------------------------------//
struct node
{
    int data;
    struct node *next;
};
struct node *front;
struct node *rear;
 
void enqueue(int val)
{
    struct node *ptr;

    ptr = (struct node *)malloc(sizeof(struct node));
    if (ptr == NULL)
    {
        printf("\nOVERFLOW\n");
        return;
    }
    else
    {
        ptr->data = val;
        if (front == NULL)
        {
            front = ptr;
            rear = ptr;
            front->next = NULL;
            rear->next = NULL;
        }
        else
        {
            rear->next = ptr;
            rear = ptr;
            rear->next = NULL;
        }
    }
}
void dequeue ()
{
    struct node *ptr;
    if (front == NULL)
    {
        printf("\nUNDERFLOW\n");
        return;
    }
    else
    {
        ptr = front;
        front = front->next;
        free(ptr);
    }
}
void display()
{
    struct node *ptr;
    ptr = front;
    if (front == NULL)
    {
        printf("\nEmpty queue\n");
    }
    else
    {
        printf("\nThe current queue is : \n");
        printf("Printing values .....\n");
        while (ptr != NULL)
        {
            printf("\n%d\n", ptr->data);
            ptr = ptr->next;
        }
    }
}

void Transfer(int size){

    int *arr = malloc(sizeof(int)*size);

    for (int i = 0; i < size; i++)
    {
        if (peek() < front->data && !isEmpty())
        {
            arr[i] = pop();
        }
        else
        {
            arr[i] = front->data;dequeue();
        }
    }
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    
}
int main()
{
    int m,n;
    printf("Enter size of stack : ");
    scanf("%d",&m);
    printf("Enter size of queue : ");
    scanf("%d",&n);

    st = createStack(m); 
    int val;
    for (int i = 0; i < m; i++)
    {
        printf("Enter value for stack:");
        scanf("%d" , &val);
        push(val);//8 7 5 2 1
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter value for queue:");
        scanf("%d" , &val);
        enqueue(val);//3 4 6 9 10
    }
    
    
    // push(8);push(7);push(5);push(2);push(1);
    
    // enqueue(3);enqueue(4);enqueue(6);enqueue(9);enqueue(10);

    // display();

    Transfer(m+n);
    
}