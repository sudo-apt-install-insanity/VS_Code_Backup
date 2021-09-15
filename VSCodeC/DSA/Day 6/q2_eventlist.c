#include <stdio.h>
#include <stdlib.h>
typedef struct Node node;
struct Node{
    char name[20];
    char type;
    int ph_number;
    node *next;
};
void insert_at_beg(node **,node *);
node *delete_from_beg(node **);
node *make_node();
void display(node *);
int main(){
    node *master = NULL;
    node **master_ref = &master;
    int choice;
    do{
        printf("Enter Info : \n");
        node *info = make_node();
        if(info->type == 'S' || info->type == 'G' || info->type == 'O' || info->type == 'D' )
            insert_at_beg(master_ref,info);
        else{
            printf("Department not in correct format.Try again!!\n");
            fflush(stdin);
            continue;
        }

        printf("Enter 0 to exit or any other number to continue : ");
        scanf("%d",&choice);
        fflush(stdin);
    }while(choice != 0);
    node *s,*g,*o,*d;
    s = g = o = d = NULL;
    while(master){
        switch (master->type)
        {
        case 'S':
            insert_at_beg(&s,delete_from_beg(master_ref));
            break;
        case 'G':
            insert_at_beg(&g,delete_from_beg(master_ref));
            break;
        case 'O':
            insert_at_beg(&o,delete_from_beg(master_ref));
            break;
        case 'D':
            insert_at_beg(&d,delete_from_beg(master_ref));
            break;        
        default:
            break;
        }
    }
    printf("<----------------------------------->\n");
    printf("Students : \n");
    display(s);
    printf("<----------------------------------->\n");
    printf("Guests : \n");
    display(g);
    printf("<----------------------------------->\n");
    printf("Organizing Team : \n");
    display(o);
    printf("<----------------------------------->\n");
    printf("Delegates : \n");
    display(d);
    printf("<----------------------------------->\n");
}
void insert_at_beg(node **p,node *temp){
    temp->next = *p;
    *p = temp;
}
node *delete_from_beg(node **p){
    node *temp = *p;
    *p = (*p)->next;
    return temp;
}
node *make_node(){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Enter name : ");
    scanf("%[^\n]%*c",temp->name);
    printf("Enter type : ");
    scanf("%c",&temp->type);
    printf("Enter phone number : ");
    scanf("%d",&temp->ph_number);
    return temp;
}
void display(node *curr){
    if (!curr)
        printf("EMPTY.\n");
    int i = 1;
    while (curr != NULL)
    {
        
        printf("Name : %s\n",curr->name);
        printf("Phone No. : %d\n",curr->ph_number);
        curr = curr->next;
        i++;
        printf("\n");
    }
}