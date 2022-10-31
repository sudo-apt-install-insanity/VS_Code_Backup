/*How do you check if a given linked list contains a cycle? How do you find the starting node of
the cycle?*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main(){
    node *head = NULL;
    node *fast = NULL;
    node *slow = NULL;

    int n, i;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        node *temp = (node *)malloc(sizeof(node));
        node *traverse = NULL;
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
    head->next->next->next->next = head->next;


    slow = head;
    fast = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            printf("The linked list contains a cycle");
            printf("Starting of the cycle is: %d\n", slow->data);
            break;
        }
    }

}