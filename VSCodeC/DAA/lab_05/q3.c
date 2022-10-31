//How do you find the third node from the end in a singly linked list?

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main(){
    node *head = NULL;
    node *temp = NULL;

    int n, i;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        node *traverse = NULL;
        temp = (node *)malloc(sizeof(node));
        printf("Enter the data: ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if(head == NULL){
            head = temp;
        }
        else{
            traverse = head;
            while(traverse->next != NULL){
                traverse = traverse->next;
            }
            traverse->next = temp;
            
        }
    }
    temp = head;
    while(temp->next->next->next != NULL){
        temp = temp->next;
    }
    printf("The third node from the end is: %d", temp->data);
    

}