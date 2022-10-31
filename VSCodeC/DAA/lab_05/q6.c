//How do you reverse a singly linked list without recursion?

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

int main(){
    node *head = NULL;
    node *q = NULL;
    node *p = NULL;
    node *r = NULL;
    node *traverse = NULL;

    int n, i;
    printf("Enter the number of elements in the linked list: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        q = (struct node *)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d", &q->data);
        q->next = NULL;
        if(head == NULL){
            head = q;
        }
        else{
            traverse = head;
            while(traverse->next != NULL){
                traverse = traverse->next;
            }
            traverse->next = q;
        }
    }
    q = head;
    while(q->next != NULL){
        r = q->next;
        q->next = r->next;
        r->next = head;
        head = r;
    }
    q = head;
    while(q != NULL){
        printf("%d ", q->data);
        q = q->next;
    }
}