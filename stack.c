#include<stdio.h>
#define MAX 10
int stack[MAX],top,value,i;

void push(){
    printf("enter the element to push");
    scanf("%d",&value);
    if(top==MAX-1)
        printf("The stack is in overflow condition");
   else{
        top = top + 1;
        stack[top] = value;
    printf("the elements in the stack after push operation are :\n");
    for(i = 0; i <= top; i++)
        {
            printf("%d ",stack[i]);
        }
    printf("\n");
}
}
void pop()
{
    if (top == -1) {
        printf("The stack is in underflow condition\n");
    } else {
        printf("Popped element: %d\n", stack[top]);
        top = top - 1;
        printf("The elements in the stack after pop operation are:\n");
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
void display(){
      if (top == -1)
    {printf("The stack is empty");
    }
    else{
    printf("The elements in the stack are:\n");
        for (i = 0; i <= top; i++) {
            printf("%d ", stack[i]);
        }
    }
        printf("\n");
}
int main() {
    int n, choice;
    top = -1;
    while (1) {
        printf("\nStack Operations Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                push();
                break;
            case 2:
                pop();
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
