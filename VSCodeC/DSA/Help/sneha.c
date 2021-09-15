#include <stdio.h>
#include <stdlib.h>
typedef struct stack stack;

struct stack{
    int top;
    int capacity;
    int *array;
};

stack* create_stack(int capacity){
    stack *temp;
    temp = malloc(sizeof(stack));
    temp->capacity = capacity;
    temp->top = -1;
    temp->array = malloc(temp->capacity*sizeof(int));
}
int main(){
    stack *st = create_stack(100);
}