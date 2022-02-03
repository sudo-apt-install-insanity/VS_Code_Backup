#include <stdio.h>
#include <stdlib.h>
typedef struct Node node;
struct Node{
    char name_1482[20];
    char dept_1482;
    char father_name_1482[20];
    long ph_number_1482;
    char location_1482[20];
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
        if(info->dept_1482 == 'C')
            insert_at_beg(master_ref,info);
        else if(info->dept_1482 == 'I')
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
    while(traverse->next->dept_1482 != 'I')
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
    scanf("%[^\n]%*c",temp->name_1482);
    printf("Enter father's name : ");
    scanf("%[^\n]%*c",temp->father_name_1482);
    printf("Enter location : ");
    scanf("%[^\n]%*c",temp->location_1482);
    printf("Enter department : ");
    scanf("%c",&temp->dept_1482);
    printf("Enter phone number : ");
    scanf("%l",&temp->ph_number_1482);
    fflush(stdin);
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
        printf("Student Name : %s\n", curr->name_1482);
        printf("Student Department : %c\n", curr->dept_1482);
        printf("Student Father's Name : %s\n", curr->father_name_1482);
        printf("Student Phone No. : %l\n", curr->ph_number_1482);
        printf("Student Location : %s\n", curr->location_1482);
        printf("<----------------------------------->\n");
        curr = curr->next;
        i++;
        printf("\n");
    }
}