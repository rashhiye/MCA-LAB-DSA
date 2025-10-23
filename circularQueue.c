#include<stdio.h>
#include<stdlib.h>
#define max 5
int queue[max], front = -1, rear = -1;
void enqueue(int value) {
    if ((front == 0 && rear == max - 1) || (rear == (front - 1) % (max - 1))) {
        printf("Queue is full\n");
        return;
    } 
    else if (front == -1) { 
        front = rear = 0;
        queue[rear] = value;
    } 
    else if (rear == max - 1 && front != 0) {
        rear = 0;
        queue[rear] = value;
    } 
    else {
        rear++;
        queue[rear] = value;
    }
    printf("Inserted -> %d\n", value);
}

void dequeue() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    int data = queue[front];
    queue[front] = -1;
    if (front == rear) {
        front = -1;
        rear = -1;
    } 
    else if (front == max - 1) {
        front = 0;
    } 
    else {
        front++;
    }
    printf("Deleted -> %d\n", data);
}
void display() {
    if (front == -1) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements: ");
    if (rear >= front) {
        for (int i = front; i <= rear; i++)
            printf("%d ", queue[i]);
    } else {
        for (int i = front; i < max; i++)
            printf("%d ", queue[i]);
        for (int i = 0; i <= rear; i++)
            printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;
    while (1) {
        printf("\nCircular Queue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the value to enqueue: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}