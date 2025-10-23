#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;
void insertatAtBeginning(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if(head == NULL){
        head = newNode;
        newNode->next = head; 
        return;
    }
    struct Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head; 
    head = newNode; 
}
void insertAtEnd(int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        newNode->next = head; 
        return;
    }
    struct Node* temp = head;
    while(temp->next != head){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->next = head; 
}

void insertatPosition(int data, int position){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if(position == 0){
        insertatAtBeginning(data);
        return;
    }
    struct Node* temp = head;
    for(int i=0; i<position-1 && temp->next != head; i++){
        temp = temp->next;
    }
    if(temp->next == head && position > 1){
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteatposition(int position){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    if(position == 0){
        if(head->next == head){ 
            free(head);
            head = NULL;
            return;
        }
        while(temp->next != head){
            temp = temp->next;
        }
        struct Node* nodeToDelete = head;
        temp->next = head->next;
        head = head->next; 
        free(nodeToDelete);
        return;
    }
    for(int i=0; i<position-1 && temp->next != head; i++){
        temp = temp->next;
    }
    if(temp->next == head || temp->next->next == head && position > 1){
        printf("Position out of bounds\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}
    void diasplay()
{
    struct Node* temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(head: %d)\n", head->data);
}
    int main()
{
   
    while(1)
    {
        int choice, data, position;
        printf("\nCircular Linked List Operations Menu:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertatAtBeginning(data);
                break;
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position to insert at (0-based index): ");
                scanf("%d", &position);
                insertatPosition(data, position);
                break;
            case 4:
                printf("Enter position to delete (0-based index): ");
                scanf("%d", &position);
                deleteatposition(position);
                break;
            case 5:
                diasplay();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice, please try again.\n");
        }
    }
    return 0;
}