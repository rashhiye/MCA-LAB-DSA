#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Insert at beginning
void insertAtBeginning(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = *head;
    *head = newNode;
}

// Insert at end
void insertAtEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
}

// Insert at specific position
void insertAtPosition(struct Node** head, int value, int position) {
    if (position == 0) {
        insertAtBeginning(head, value);
        return;
    }

    struct Node* newNode = createNode(value);
    struct Node* temp = *head;

    for (int i = 0; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range. Inserting at the end.\n");
        insertAtEnd(head, value);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete by value
void deleteNode(struct Node** head, int key) {
    struct Node *temp = *head, *prev = NULL;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        printf("Node with value %d deleted.\n", key);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list.\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("Node with value %d deleted.\n", key);
}

// Display list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct Node* head = NULL;
    int choice, value, position;

    do {
        printf("\n---- Linked List Menu ----\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete Node by Value\n");
        printf("5. Display List\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                insertAtBeginning(&head, value);
                break;

            case 2:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                insertAtEnd(&head, value);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position (0-based index): ");
                scanf("%d", &position);
                insertAtPosition(&head, value, position);
                break;

            case 4:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                deleteNode(&head, value);
                break;

            case 5:
                displayList(head);
                break;

            case 0:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 0);

    return 0;
}
