#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node node;
struct Node{
    int cab_num;
    char status;
    char name[20];
    char gender;
    char disease[20];
    node *next;
};
int menu();
void create_cabin_list(int ,node **);
void admission_request(node *,node **,node **);
void discharge_request(node *,node **,node **);
int update_node(node *);
node *make_node();
node *make_empty_node();
void insert_at_end(node **,char);
node *delete_from_beg(node **);
void display_cabin_list(node *);
void display_waiting_list(node *);
int main(){
    node *master = NULL,*w_male = NULL,*w_female = NULL;
    node **master_ref = &master;
    int no_of_cabs;
    printf("Enter total number of cabins : ");
    scanf("%d",&no_of_cabs);
    fflush(stdin);
    create_cabin_list(no_of_cabs,master_ref);
    int flag = -1;
    do{
        switch (menu())
        {
        case 1:
            admission_request(master,&w_male,&w_female);
            break;
        case 2:
            discharge_request(master,&w_male,&w_female);
            break;
        case 3:
            printf("\nCabin List : \n");
            display_cabin_list(master);
            break;
        case 4:
            printf("\nWaiting List(Male) : \n");
            display_waiting_list(w_male);
            break;
        case 5:
            printf("\nWaiting List(Female) : \n");
            display_waiting_list(w_female);
            break;
        case 6:
            flag = 0;
            break;
        default:
            printf("Invalid Choice!Try again.\n");
            break;
        }
    }while(flag);
}
int menu(){
    int choice;
    printf("1.Admission Request.\n");
    printf("2.Discharge Request.\n");
    printf("3.Cabin List.\n");
    printf("4.Waiting List(Male).\n");
    printf("5.Waiting List(Female).\n");
    printf("6.Exit.\n");
    printf("Enter choice : ");
    scanf("%d",&choice);
    fflush(stdin);
    return choice;
}
void create_cabin_list(int n,node **master_ref){
    node *last;
    for (int i = 1; i <= n; i++)
    {
        node *temp = make_empty_node();
        temp->cab_num = i;
        if(*master_ref == NULL){
            temp->next = (*master_ref);
            *master_ref = temp;
            last = temp;
        }else{
            last->next = temp; 
            temp->next = NULL;
            last = last->next;
        }
    }
    
}
void admission_request(node *master,node **w_male,node **w_female){
    node *p = master;
    char gender;
    int done = -1;
    printf("Enter gender : ");
    scanf("%c",&gender);
    fflush(stdin);
    while(p){
        if(gender == 'M'){
            if(p->cab_num % 2 != 0 && p->status == 'N'){
                p->gender = 'M';
                done = update_node(p);
            }
        }
        else if(gender == 'F'){
            if(p->cab_num % 2 == 0 && p->status == 'N'){
                p->gender = 'F';
                done = update_node(p);
            }
        }
        if(done == 1)
            break;
        p = p->next;
    }
    if(done == -1){
        if(gender == 'M')
            insert_at_end(w_male,'M');
        else if(gender == 'F')
            insert_at_end(w_female,'F');
        else
            printf("Gender in incorrect format! No changes made.\n");
    }
}
void discharge_request(node *master,node **w_male,node **w_female){
    int cabin_number,done = -1;
    node *p = master;
    printf("Enter cabin number for discharge : ");
    scanf("%d",&cabin_number);
    if(cabin_number % 2 == 0){
        node *data = delete_from_beg(w_female);
        while(p){
            if(p->cab_num == cabin_number){
                strcpy(p->name,data->name);
                strcpy(p->disease,data->disease);
                done = 1;
            }
            p = p->next;
            if(done == 1)
                break;
        }
        if(done == -1){
            p->status = 'N';
        }
    }else{
        node *data = delete_from_beg(w_male);
        if(data == NULL){
            p->status = 'N';
            return;
        }
        while(p){
            if(p->cab_num == cabin_number){
                strcpy(p->name,data->name);
                strcpy(p->disease,data->disease);
                done = 1;
            }
            p = p->next;
            if(done == 1)
                break;  
        }
        if(done == -1){
            p->status = 'N';
        }
    }
}
int update_node(node *p){
    printf("Enter name : ");
    scanf("%[^\n]%*c",p->name);
    printf("Enter disease : ");
    scanf("%[^\n]%*c",p->disease);
    p->status = 'Y';
    return 1;
}
node *make_node(){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    printf("Enter name : ");
    scanf("%[^\n]%*c",temp->name);
    printf("Enter disease : ");
    scanf("%[^\n]%*c",&temp->disease);
    return temp;
}
node *make_empty_node(){
    node *temp;
    temp = (node *)malloc(sizeof(node));
    strcpy(temp->name,"");
    strcpy(temp->disease,"");
    temp->gender = '-';
    temp->status = 'N';
    return temp;
}
void insert_at_end(node **master_ref,char gender){
    node *temp = make_node();
    temp->gender = gender;
    if(*master_ref == NULL){
        temp->next = (*master_ref);
        *master_ref = temp;
    }else{
        node *p = *master_ref;
        while(p->next) p = p->next;
        p->next = temp; 
        temp->next = NULL;
    }
}
node *delete_from_beg(node **p){
    if(*p == NULL)
        return NULL;
    node *temp = *p;
    *p = (*p)->next;
    return temp;
}
void display_cabin_list(node *curr){
    if (!curr)
        printf("EMPTY.\n\n");
    int no_print = -1;
    while (curr != NULL)
    {
        if(curr->status == 'Y'){
            printf("--\n");
            printf("| Name : %s\n",curr->name);
            printf("| Gender : %c\n",curr->gender);
            printf("| Cabin Number : %d\n",curr->cab_num);
            printf("| Disease : %s\n",curr->disease);
            printf("--\n");
            no_print = 1;
        }
        curr = curr->next;
        printf("\n");
    }
    if(no_print == -1)
        printf("EMPTY.\n\n");
}
void display_waiting_list(node *curr){
    if (!curr)
        printf("EMPTY.\n");
    while (curr != NULL)
    {
        printf("Name : %s\n",curr->name);
        printf("Gender : %c\n",curr->gender);
        printf("Disease : %s\n",curr->disease);
        curr = curr->next;
        printf("\n");
    }
}