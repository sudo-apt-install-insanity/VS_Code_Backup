/*
*WAP using a function that sort an array of integers
*using stacks and also uses bubble sort.
*/
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
int top(stack *p);
void display(stack *p);
int main(){
    int size;
    printf("Enter size of array : ");
    scanf("%d",&size);
    int *array = malloc(sizeof(size));
    printf("Enter elements : ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d",&array[i]);
    }
    printf("Original array : [");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ",array[i]);
    }
    printf("]\n");


    stack *s1 = malloc(sizeof(stack));
    s1->size = size;
    s1->arr = malloc(sizeof(int) * s1->size);
    s1->top = -1;

    stack *s2 = malloc(sizeof(stack));
    s2->size = size;
    s2->arr = malloc(sizeof(int) * s2->size);
    s2->top = -1;

    //*Pushing all elements of array to stack s1.
    for (int i = 0; i < size; i++)
    {
        push(s1,array[i]);
    }
    
    
    
    for (int i = 0; i < size; i++)
    {
        if(i % 2 == 0){
            while(!isEmpty(s1)){
                int t = top(s1);
                pop(s1);
                if(isEmpty(s2)){
                    push(s2,t);
                }
                else{
                    if(top(s2) > t){
                        int temp = top(s2);
                        pop(s2);
                        push(s2,t);
                        push(s2,temp);
                    }
                    else   
                        push(s2,t);
                }
            }
            array[size-1-i] = top(s2);
            pop(s2);
        }
        else{
            while(!isEmpty(s2)){
                int t = top(s2);
                pop(s2);
                if(isEmpty(s1)){
                    push(s1,t);
                }  
                else{
                    if(top(s1) > t){
                        int temp = top(s1);
                        pop(s1);
                        push(s1,t);
                        push(s1,temp);
                    }
                    else   
                        push(s1,t);
                }
            }
            array[size-1-i] = top(s1);
            pop(s1);
        }
        printf("%d\n",i);
    }
    printf("Sorted array : [");
    for (int i = 0; i < size; i++)
    {
        printf("%d, ",array[i]);
    }
    printf("]\n");
    
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