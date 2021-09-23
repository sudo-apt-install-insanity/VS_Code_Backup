#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
typedef struct stack stack;
struct stack {
    int top;
    int size;
    int *arr;
};
int isFull(stack *p);
int isEmpty(stack *p);
void push(stack *p,int element);
int pop(stack *p);
void display(stack *p);
int main(){
    stack *master = malloc(sizeof(stack));
    printf("Enter size of stack : ");
    scanf("%d",&master->size);
    master->arr = malloc(sizeof(int) * master->size);
    master->top = -1;

    stack *tStack = malloc(sizeof(stack));
    tStack->size = master->size;
    tStack->arr = malloc(sizeof(int) * tStack->size);
    tStack->top = -1;

    int flag = 1;
    
    while(flag && !isFull(master))
    {
        int ch,element;
        printf("Press 1 to enter element or 0 to exit : ");
        scanf("%d",&ch);
        if(ch == 0){
            flag = 0;
            continue;
        }
        printf("Enter element : ");
        scanf("%d",&element);
        push(master,element);
    }
    printf("Original stack : \n");
    display(master);
    while (!isEmpty(master))
    {
        int temp;
        temp = pop(master);
        while(!isEmpty(tStack) && top(tStack) < temp){   
            push(master,pop(tStack));
        }
        push(tStack,temp);
    }
    printf("Sorted stack :\n");
    display(tStack);
}
int isFull(stack *p){
    if(p->top == p->size - 1)
        return 1;
    else
        return 0;
}
int isEmpty(stack *p){
    if(p->top == -1)
        return 1;
    else    
        return 0;
}
int top(stack *p){
    return p->arr[p->top];
}
void push(stack *p,int element){
    if(isFull(p)){
        printf("Stack Overflow!\n");
        return;
    }
    // printf("Enter element : ");
    // scanf("%d",&element);
    p->arr[++(p->top)] = element;
}
int pop(stack *p){
    if(isEmpty(p)){
        printf("Stack Underflow!\n");
        return INT_MIN;
    }
    int element = 0;
    element = p->arr[(p->top)--];
    // printf("Popped element is : %d\n",element);
    return element;
}

void display(stack *p){
    printf("Elements : \n");
    for(int i = p->top;i >= 0;i--){
        printf("%d\n",p->arr[i]);
    }
    printf("\n");
}