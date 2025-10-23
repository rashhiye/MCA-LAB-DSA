#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};
struct Node* head = NULL;

void insertAtBeginning(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
        head->prev = newNode;

    head = newNode;
}

void insertAtEnd(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}


void insertAnyPosition(int data, int position)
{
    if (position == 0)
    {
        insertAtBeginning(data);
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = head;
    for (int i = 0; temp != NULL && i < position - 1; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL)
        temp->next->prev = newNode;

    temp->next = newNode;
}

void delete(int position)
{
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = head;

    if (position == 0)
    {
        head = head->next;
        if (head != NULL)
            head->prev = NULL;
        free(temp);
        return;
    }

    for (int i = 0; temp != NULL && i < position; i++)
        temp = temp->next;

    if (temp == NULL)
    {
        printf("Position out of bounds\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}
void diasplay()
{
    struct Node* temp = head;
    if (temp == NULL)
    {
        printf("List is empty\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main()
{
   
    while(1)
    {
        int choice, data, position;
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Any Position\n");
        printf("4. Delete at Position\n");
        printf("5. Display\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
            case 1:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Enter data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Enter data: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAnyPosition(data, position);
                break;
            case 4:
                printf("Enter position: ");
                scanf("%d", &position);
                delete(position);
                break;
            case 5:
                diasplay();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
}