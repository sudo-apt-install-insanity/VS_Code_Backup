#include<stdio.h>
#include <stdlib.h>
typedef struct stack stack;
struct stack
{
    int size;
    int top;
    int *s;
};

void create(stack *st)
{
    st->top = -1;
    printf("Enter the size of the stack : ");
    scanf("%d", &st->size);
    st->s = (int *)malloc(st->size*sizeof(int));
}

void push(stack *st, int x)
{
    if(st->top == st->size-1)
        printf("---OVERFLOW OCCURRED---");  
    else
    {
        st->s[++(st->top)] = x;
    }          
}

int pop(stack *st)
{
    int element = -1;
    if(st->top == -1)
        printf("---UNDERFLOW OCCURRED---");
    else
    {
        element = st->s[st->top];
        st->top--;
    }
    return element;     //returns -1 when no element is present  
}

void display(stack st)
{
    if(st.top == -1)
        printf("\nSTACK IS EMPTY");
    else
    {
        printf("\nThe stack is as follows :\n");
        for(int i=st.top; i>-1; i--)
            printf("%d\n", st.s[i]);
    }
}

void main()
{
    int choice, element;
    stack *st;
    st = malloc(sizeof(stack));
    create(st);
    do{
        printf("Enter  1. Push element   2. Pop elememt   3. Display   4. Exit\t: ");
        scanf("%d", &choice);    
        switch (choice)
        {
        case 1:            
            printf("\nEnter element : ");
            scanf("%d",&element);
            push(st, element);
            break;
        
        case 2:
            pop(st);
        
        case 3:
            display(*st);
        
        default:
            printf("\nWrong choice!!");    
        }
    }while(choice != 4);
}
    // do
    // {
    //     printf("Enter element. Enter -1 to stop\n");
    //     scanf("%d", element);
    //     push(&st, element);
    // }while(element != -1);
    // push(&st, 10);
    // push(&st, 20);
    // push(&st, 30);
    // push(&st, 40);
    // push(&st, 50);
    // display(st);
    // pop(&st);
    // pop(&st);
    // display(st);