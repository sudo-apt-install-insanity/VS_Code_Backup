#include <stdio.h>
#include <stdlib.h>

typedef struct node_l *node;
struct node_l{
    int exp;
    int coeff;
    node next;
};

node start = NULL;

node create(node);
node display(node);
node addPoly(node, node, node);

void main()
{
    node poly1 = NULL, poly2 = NULL, poly3 = NULL;
    printf("Enter the polynomials as follows: ");
    printf("\nFor polynomial 1 : \n");    
    poly1 = create(poly1);
    printf("\nFor polynomial 2 : \n");  
    poly2 = create(poly2);    
    poly3 = addPoly(poly1, poly2, poly3);
    poly3 = display(poly3);
}

node create(node start)
{
    node ptr;
    int n=0, c, e; 
    
    do{
        printf("\nEnter 1 to continue and -1 to stop\n");
        scanf("%d", &n);
        if(n==-1)
            break;
        printf("\nEnter the coefficient : ");
        scanf("%d", &c);
        printf("\nEnter the exponent : ");
        scanf("%d", &e);

        if(start == NULL)
        {
            struct node_l *newnode = (struct node_l*)malloc(sizeof(struct node_l));
            newnode->coeff = c;
            newnode->exp = e;
            newnode->next = NULL;
            start = newnode;
        }

        else
        {
            ptr = start;
            while(ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            struct node_l *newnode = (struct node_l*)malloc(sizeof(struct node_l));
            newnode->coeff = c;
            newnode->exp = e;
            newnode->next = NULL;
            ptr->next = newnode;         
        }

    }while(n != -1);

    return start;
}

node display(node start)
{
    node ptr;
    ptr = start;
    
    printf("\nThe polynomial is : ");
    while(ptr != NULL)
    {
        printf("(%dx^%d)", ptr->coeff, ptr->exp);
        if(ptr->next != NULL)
            printf(" + ");
        ptr = ptr->next;

    }
    return start;
}

node addPoly(node poly1, node poly2, node s)
{
    node p, q, ptr;
    if(poly1 == NULL && poly2 == NULL)
    {
        printf("\nBoth lists are empty ");
        exit(0);
    }
    p = poly1;
    q = poly2;
    struct node_l *newnode = (struct node_l*)malloc(sizeof(struct node_l));
    newnode->next = NULL;
    while(p != NULL && q != NULL)
    {
        if(p->exp < q->exp)
        {
            newnode->coeff = q->coeff;
            newnode->exp = q->exp;
            q = q->next;
        }
        else if(p->exp > q->exp)
        {
            newnode->coeff = p->coeff;
            newnode->exp = p->exp;
            p = p->next;
        }
        else
        {
            newnode->coeff = p->coeff + q->coeff;
            newnode->exp = p->exp;
            p=p->next;
            q=q->next;
        }
        if(s == NULL)
            s=newnode;
        else
        {
            ptr = s;
            while(ptr->next != NULL)
                ptr = ptr->next;
            ptr->next = newnode;
        }
        while (p!=NULL)
        {
            if(s == NULL)
                s=newnode;
            else
            {
                ptr = s;
                while(ptr->next != NULL)
                    ptr = ptr->next;
                newnode->coeff = p->coeff;
                newnode->exp = p->exp;
                p=p->next;
                ptr->next = newnode;
            }
            while (q != NULL)
            {
                if(s == NULL)
                    s = newnode;
                else
                {
                    ptr = s;
                    while(ptr->next != NULL)
                        ptr = ptr->next;
                    ptr->next = newnode;
                    newnode->coeff = q->coeff;
                    newnode->exp = q->exp;
                    q = q->next;
                }
            }            
        }       
    }
    return s;
}