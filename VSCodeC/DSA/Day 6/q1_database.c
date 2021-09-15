#include <stdio.h>
#include <stdlib.h>
typedef struct Node node;
struct Node{
    char name[20];
    char dept;
    char father_name[20];
    int ph_number;
    char location[20];
    node *next;
};
void insert_at_beg(node **,node *);
void insert_at_end(node **,node *);
node *make_node();
void display(node *);
int main(){
    node *master = NULL;
    node **master_ref = &master;
    int choice;
    do{
        printf("Enter Info : \n");
        node *info = make_node();
        if(info->dept == 'C')
            insert_at_beg(master_ref,info);
        else if(info->dept == 'I')
            insert_at_end(master_ref,info);
        else{
            printf("Department not in correct format.Try again!!\n");
            continue;
        }

        printf("Enter 0 to exit or any other number to continue : ");
        scanf("%d",&choice);
        fflush(stdin);
    }while(choice != 0);
    node *cse = NULL;
    node *it = NULL;
    cse = master;
    node *traverse = master;
    while(traverse->next->dept != 'I')
        traverse = traverse->next;
    it = traverse->next;
    traverse->next = NULL;
    printf("CSE Students : \n");
    display(cse);
    printf("\n\nIT Students : \n");
    display(it);
}
void insert_at_beg(node **p,node *temp){
    temp->next = *p;
    *p = temp;
}
void insert_at_end(node **p,node *temp){
    node *insert = *p;
    while(insert->next != NULL){
        insert = insert->next;
    }
    insert->next = temp;
    temp->next = NULL;
}
node *make_node(){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Enter name : ");
    scanf("%[^\n]%*c",temp->name);
    printf("Enter father's name : ");
    scanf("%[^\n]%*c",temp->father_name);
    printf("Enter location : ");
    scanf("%[^\n]%*c",temp->location);
    printf("Enter department : ");
    scanf("%c",&temp->dept);
    printf("Enter phone number : ");
    scanf("%d",&temp->ph_number);
    return temp;
}
void display(node *curr){
    printf("Current elements in list : \n");
    if (!curr)
        printf("EMPTY.\n");
    int i = 1;
    while (curr != NULL)
    {
        printf("<----------------------------------->\n");
        printf("Student Name : %s\n", curr->name);
        printf("Student Department : %c\n", curr->dept);
        printf("Student Father's Name : %s\n", curr->father_name);
        printf("Student Phone No. : %d\n", curr->ph_number);
        printf("Student Location : %s\n", curr->location);
        printf("<----------------------------------->\n");
        curr = curr->next;
        i++;
        printf("\n");
    }
}