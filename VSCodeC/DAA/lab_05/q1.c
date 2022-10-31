//How do you find the middle element of a singly linked list in one pass?

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main(){
    node *head = NULL;
    node *temp = NULL;
    node *mid = NULL;
    node *traverse = NULL;
    
    int n, i;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
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
    mid = head;
    while(temp != NULL && temp->next != NULL){
        mid = mid -> next;
        temp = temp->next->next;
    }
    printf("The middle element of the linked list is: %d", mid->data);

}