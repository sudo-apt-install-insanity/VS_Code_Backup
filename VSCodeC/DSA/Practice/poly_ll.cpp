#include <stdio.h>
#include <stdlib.h>
typedef struct poly_node poly_node;

struct poly_node{
    int exp;
    int coeff;
    poly_node *next;
};

poly_node *create_polynomial();
void print_polynomial(poly_node **);
void insert_at_end(poly_node **,poly_node **);
void insert_at_end(poly_node **,poly_node **,int ,int );
poly_node *create_poly_node();
poly_node *create_poly_node(int ,int );
void add_poly(poly_node **);
void sub_poly(poly_node **);
void mul_poly(poly_node **);
void sort(poly_node **);
void remove_duplicates(poly_node **);
int menu();
int main(){
    poly_node *master_head = NULL;
    printf("Enter first polynomial : \n");
    master_head = create_polynomial();
    print_polynomial(&master_head);
    bool flag = true;
    do{
        switch (menu())
        {
        case 1:
            printf("\e[1;1H\e[2J");
            add_poly(&master_head);
            break;
        case 2:
            printf("\e[1;1H\e[2J");
            sub_poly(&master_head);
            break;
        case 3:
            printf("\e[1;1H\e[2J");
            mul_poly(&master_head);
            break;
        case 4:
            printf("\e[1;1H\e[2J");
            print_polynomial(&master_head);
            break;
        case 5:
            printf("\e[1;1H\e[2J"); 
            master_head = create_poly_node(0,0);
            break;
        case 6:
            flag = false;
        default:
            printf("Invalid Choice!!Try again.");
            break;
        }
    }while(flag);
       
}
int menu(){
    int ch;
    printf("1.Addition\n2.Subtraction\n3.Multiplication\n4.Display polynomial\n5.Reset polynomial\n6.Exit\nEnter choice : ");
    scanf("%d",&ch);
    return ch;
}
poly_node *create_poly_node(){
    poly_node *temp;
    int exp,coeff;
    temp = (poly_node *)malloc(sizeof(poly_node));
    printf("Enter coefficient and exponent : ");
    scanf("%d%d",&coeff,&exp);
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}
poly_node *create_poly_node(int coeff,int exp){
    poly_node *temp;
    temp = (poly_node *)malloc(sizeof(poly_node));
    temp->coeff = coeff;
    temp->exp = exp;
    temp->next = NULL;
    return temp;
}
void insert_at_end(poly_node **head_ref,poly_node **last){
    poly_node *temp = create_poly_node();
    if(*head_ref == NULL){
        temp->next = (*head_ref);
        *head_ref = temp;
        *last = temp;
    }else{
        (*last)->next = temp; 
        temp->next = NULL;
        *last = (*last)->next;
    }
}
void insert_at_end(poly_node **head_ref,poly_node **last,int coeff,int exp){
    poly_node *temp = create_poly_node(coeff,exp);
    if(*head_ref == NULL){
        temp->next = (*head_ref);
        *head_ref = temp;
        *last = temp;
    }else{
        (*last)->next = temp; 
        temp->next = NULL;
        *last = (*last)->next;
    }
}
poly_node *create_polynomial(){
    poly_node *head_ref = NULL;
    poly_node *last = head_ref;
    int ch;
    do{
        printf("Press 1 to enter term or 0 to exit : ");
        scanf("%d",&ch);
        if(ch == 0){
            if(head_ref == NULL)
                head_ref = create_poly_node(0,0);
            break;
        }
        insert_at_end(&head_ref,&last);

    }while (ch == 1);
}
void print_polynomial(poly_node **head_ref){
    remove_duplicates(head_ref);
    poly_node *traverse = *head_ref;
    while(traverse->next){
        printf("%dx^%d + ",traverse->coeff,traverse->exp);
        traverse = traverse->next;
    }
    printf("%dx^%d\n",traverse->coeff,traverse->exp);
}
void add_poly(poly_node **master){
    printf("Enter polynomial : \n");
    poly_node *poly = create_polynomial();
    printf("  ");
    print_polynomial(master);
    printf("+ ");
    print_polynomial(&poly);
    poly_node *temp = *master;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = poly;
    remove_duplicates(master);
    sort(master);
    printf("= ");
    print_polynomial(master);
}
void sub_poly(poly_node **master){
    printf("Enter polynomial : \n");
    poly_node *poly = create_polynomial();
    printf("  ");
    print_polynomial(master);
    printf("- ");
    print_polynomial(&poly);
    poly_node *temp = *master;
    while(temp->next){
        temp = temp->next;
    }
    temp->next = poly;
    poly_node *i,*j,*prev_j;
    i = *master;
    while (i)
    {
        prev_j = i;
        j = i->next;
        while (j)
        {
            if(i->exp == j->exp){
                temp = j;
                i->coeff = i->coeff - j->coeff;
                prev_j->next = j->next;
                j = j->next;
                free(temp);
            }else{
                prev_j = j;
                j = j->next;
            }
        }
        i = i->next;
    }
    sort(master);
    printf("= ");
    print_polynomial(master);
}
void mul_poly(poly_node **master){
    printf("Enter polynomial : \n");
    poly_node *poly = create_polynomial();
    printf("  ");
    print_polynomial(master);
    printf("* ");
    print_polynomial(&poly);
    poly_node *temp_master = *master;
    poly_node *temp_poly;
    poly_node *new_poly = NULL,*last = NULL;
    new_poly = last;
    int i = 1;
    while(temp_master){
        temp_poly = poly;
        while (temp_poly)
        {
            int new_coeff = temp_master->coeff*temp_poly->coeff;
            int new_exp = temp_master->exp+temp_poly->exp;
            insert_at_end(&new_poly,&last,new_coeff,new_exp);
            temp_poly = temp_poly->next;
        }
        temp_master = temp_master->next;
    }
    remove_duplicates(&new_poly);
    sort(&new_poly);
    *master = new_poly;
    printf("= ");
    print_polynomial(master);
}
void remove_duplicates(poly_node **master){
    poly_node *i,*j,*prev_j;
    i = *master;
    while (i)
    {
        prev_j = i;
        j = i->next;
        while (j)
        {
            if(i->exp == j->exp){
                i->coeff = i->coeff + j->coeff;
                prev_j->next = j->next;
                free(j);
                j = prev_j->next;
                
            }else if(j->coeff == 0){
                prev_j->next = j->next;
                free(j);
                j = prev_j->next;
            }else{
                prev_j = j;
                j = j->next;
            }
        }
        i = i->next;
    }
}
void sort(poly_node **master){
    poly_node *p,*q;
    p = *master;
    while (p){
        q = *master;
        while(q){
            if(p == q){
                q = q->next;
                continue;
            }
            if(p->exp > q->exp){
                int exp_switch,coeff_switch;

                exp_switch = p->exp;
                p->exp = q->exp;
                q->exp = exp_switch;

                coeff_switch = p->coeff;
                p->coeff = q->coeff;
                q->coeff = coeff_switch;
            }
            q = q->next;
        }
        p = p->next;
    }
}