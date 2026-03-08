#include <stdio.h>

#define MAX 100

int queue[MAX];
int front = -1, rear = -1;
int size;

void enqueue(int value){
    printf("\nTrying to enqueue %d\n", value);

    if((rear + 1) % size == front){
        printf("Queue Overflow! Cannot insert %d\n", value);
        return;
    }

    if(front == -1){
        front = rear = 0;
    }
    else{
        rear = (rear + 1) % size;
    }

    queue[rear] = value;
    printf("Inserted %d at position %d\n", value, rear);
}

void dequeue(){
    if(front == -1){
        printf("Queue Underflow! Nothing to delete\n");
        return;
    }

    printf("\nDeleting element %d from position %d\n", queue[front], front);

    if(front == rear){
        front = rear = -1;
    }
    else{
        front = (front + 1) % size;
    }
}

void display(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }

    printf("\nFinal Queue (Front to Rear): ");

    int i = front;
    while(1){
        printf("%d ", queue[i]);
        if(i == rear)
            break;
        i = (i + 1) % size;
    }
}

int main(){
    int n, m, i, x;

    printf("Enter number of elements to enqueue: ");
    scanf("%d", &n);

    size = n + 5;  // extra space to allow circular movement

    printf("Enter %d elements:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &x);
        enqueue(x);
    }

    printf("\nEnter number of dequeue operations: ");
    scanf("%d", &m);

    for(i = 0; i < m; i++){
        dequeue();
    }

    display();

    return 0;
}