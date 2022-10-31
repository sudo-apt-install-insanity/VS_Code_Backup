#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    int data;
    struct node *right;
};

struct queue
{
    int size;
    int front;
    int rear;
    struct node **node_queue; // Queue of tree nodes.
};

//function for initializing the queue
void create(struct queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->node_queue = (struct node **)malloc(q->size * sizeof(struct node *));
}

//standard queue enqueue function
int enqueue(struct queue *q, struct node *x)
{
    if ((q->rear + 1) % q->size == q->front)
        return -1;
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->node_queue[q->rear] = x;
    }
}

//standard queue dequeue function
struct node *dequeue(struct queue *q)
{
    struct node *x = NULL;

    if (q->front == q->rear)
        return NULL;
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->node_queue[q->front];
    }
    return x;
}

int is_empty(struct queue q)
{
    return q.front == q.rear;
}

//global root for easy access
struct node *root = NULL;

//creating the tree using queue
void create_tree()
{
    struct node *p, *t;
    int x;
    struct queue q;
    create(&q, 100);

    printf("Enter root value ");
    scanf("%d", &x);
    root = (struct node *)malloc(sizeof(struct node));
    root->data = x;
    root->left = root->right = NULL;
    enqueue(&q, root);

    while (!is_empty(q))
    {
        p = dequeue(&q);
        printf("Enter left child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->left = t->right = NULL;
            p->left = t;
            enqueue(&q, t);
        }
        printf("Enter right child of %d ", p->data);
        scanf("%d", &x);
        if (x != -1)
        {
            t = (struct node *)malloc(sizeof(struct node));
            t->data = x;
            t->left = t->right = NULL;
            p->right = t;
            enqueue(&q, t);
        }
    }
}

//inorder traversal
void inorder(struct node *p)
{
    if (p)
    {
        inorder(p->left);
        printf("%d ", p->data);
        inorder(p->right);
    }
}

int main()
{
    create_tree();
    printf("\nIn Order ");
    inorder(root);

    return 0;
}