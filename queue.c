#include<stdio.h>
#define MAX 10
int queue[MAX], front = -1, rear = -1, value, i;

void enqueue() {
    if (rear == MAX - 1) {
        printf("Can't insert, the Queue is full\n");
        return;
    }
    printf("Enter the element to insert in queue (enqueue operation): ");
    scanf("%d", &value);
    if (front == -1) {
        front = 0;
    }
    rear = rear + 1;
    queue[rear] = value;
    printf("The elements in queue after enqueue operation are: ");
    for (i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Can't delete, the Queue is empty\n");
        return;
    }
    printf("Deleted element: %d\n", queue[front]);
    front = front + 1;
    if (front > rear) {
        front = rear = -1;
    }
    if (front != -1) {
        printf("The elements in queue after dequeue operation are: ");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

void display() {
    if (front == -1 || front > rear) {
        printf("The queue is empty\n");
    } else {
        printf("The elements in the queue are:\n");
        for (i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}
int main() {
    int n, choice;
    while (1) {
        printf("\nQueue Operations Menu:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                printf("Exited\n");
                return 0;
            default:
                printf("Invalid choice \n");
        }
    }
    return 0;
}
