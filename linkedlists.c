#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};
struct Node* head = NULL;

void insertatAtBeginning(int data){
    struct Node* newNode =malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}
void insertatEnd(int data){
    struct Node* newNode =malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    struct Node* temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertatPosition(int data, int position){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    if(position == 0){
        newNode->next = head;
        head = newNode;
        return;
    }
    struct Node* temp = head;
    for(int i=0; i<position-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL){
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
        head = head->next;
        free(temp);
        return;
    }
    for(int i=0; i<position-1 && temp != NULL; i++){
        temp = temp->next;
    }
    if(temp == NULL || temp->next == NULL){
        printf("Position out of bounds\n");
        return;
    }
    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
}
void display(){
    struct Node* temp = head;
    if(temp == NULL){
        printf("List is empty\n");
        return;
    }
    while(temp != NULL){
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    int choice, data, position;
    while(1){
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete at Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertatAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertatEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertatPosition(data, position);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteatposition(position);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
   
