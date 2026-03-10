#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void push_front(int value)
{
    if((front == 0 && rear == MAX-1) || (front == rear + 1))
        printf("Deque Overflow\n");

    else if(front == -1)
    {
        front = rear = 0;
        deque[front] = value;
    }

    else if(front == 0)
    {
        front = MAX - 1;
        deque[front] = value;
    }

    else
    {
        front--;
        deque[front] = value;
    }
}

void push_back(int value)
{
    if((front == 0 && rear == MAX-1) || (front == rear + 1))
        printf("Deque Overflow\n");

    else if(front == -1)
    {
        front = rear = 0;
        deque[rear] = value;
    }

    else if(rear == MAX-1)
    {
        rear = 0;
        deque[rear] = value;
    }

    else
    {
        rear++;
        deque[rear] = value;
    }
}

void pop_front()
{
    if(front == -1)
        printf("Deque Underflow\n");

    else
    {
        printf("Deleted element: %d\n", deque[front]);

        if(front == rear)
            front = rear = -1;

        else if(front == MAX-1)
            front = 0;

        else
            front++;
    }
}

void pop_back()
{
    if(front == -1)
        printf("Deque Underflow\n");

    else
    {
        printf("Deleted element: %d\n", deque[rear]);

        if(front == rear)
            front = rear = -1;

        else if(rear == 0)
            rear = MAX - 1;

        else
            rear--;
    }
}

void display()
{
    int i;

    if(front == -1)
        printf("Deque is Empty\n");
    else
    {
        printf("Deque elements: ");
        i = front;

        while(i != rear)
        {
            printf("%d ", deque[i]);
            i = (i + 1) % MAX;
        }

        printf("%d\n", deque[rear]);
    }
}

void get_front()
{
    if(front == -1)
        printf("Deque is Empty\n");
    else
        printf("Front element: %d\n", deque[front]);
}

void get_back()
{
    if(front == -1)
        printf("Deque is Empty\n");
    else
        printf("Rear element: %d\n", deque[rear]);
}

int main()
{
    int choice, value;

    while(1)
    {
        printf("\n1.Push Front\n2.Push Back\n3.Pop Front\n4.Pop Back\n5.Front\n6.Back\n7.Display\n8.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                push_front(value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                push_back(value);
                break;

            case 3:
                pop_front();
                break;

            case 4:
                pop_back();
                break;

            case 5:
                get_front();
                break;

            case 6:
                get_back();
                break;

            case 7:
                display();
                break;

            case 8:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }
}