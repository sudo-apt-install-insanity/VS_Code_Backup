#include <stdio.h>
#define MAX 10
int arr[MAX];
int front = -1;
int rear = -1;

void insert_right();
void delete_left();
void delete_right();
void display();

int main()
{
    int ch = 1;
    do
    {
        int x;
        printf("\n1.Insert Right\n2.Delete Left\n3.Delete Right\n4.Display\n");
        scanf("%d", &x);
        switch (x)
        {
        case 1:
            insert_right();
            break;
        case 2:
            delete_left();
            break;
        case 3:
            delete_right();
            break;
        case 4:
            display();
            break;
        }
        printf("\n1 to Continue 0 To Exit : ");
        scanf("%d", &ch);
    } while (ch != 0);

    return 0;
}
void insert_right()
{
    int x;
    if (front == -1)
    {
        front = 0;
        rear = 0;
    }
    else if (rear == MAX - 1)
    {
        rear = 0;
    }
    else
        rear++;
    printf("Element : ");
    scanf("%d", &x);
    arr[rear] = x;
}
void delete_left()
{
    printf("Deleted Element : %d\n", arr[front]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (front == MAX - 1)
    {
        front = 0;
    }
    else
        front++;
}
void delete_right()
{
    printf("Deleted Element : %d\n", arr[rear]);
    if (front == rear)
    {
        front = -1;
        rear = -1;
    }
    else if (rear == 0)
    {
        rear = MAX - 1;
    }
    else
        rear--;
}
void display()
{
    int x = front, y = rear;
    printf("Elements :\n");
    while (x <= y)
    {
        printf("%d ", arr[x]);
        x++;
    }
}