//How are duplicate nodes removed in an unsorted linked list?

#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
}node;

int main(){
    node *head = NULL;
    node *temp = NULL;
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
    node *p1,*p2;
    p1 = p2 = head;

    while(p1 != NULL && p1->next != NULL){
        p2 = p1;
        while(p2->next != NULL){
            if(p1->data == p2->next->data){
                p2->next = p2->next->next;
            }
            else{
                p2 = p2->next;
            }
        }
        p1 = p1->next;
    }

    temp = head;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }

}