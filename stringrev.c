#include <stdio.h>
#define MAX 100

char stack1[MAX];
int top1 = -1;

void push1(char c) {
    if (top1 < MAX - 1) {
        stack1[++top1] = c;
    } else {
        printf("Stack overflow\n");
    }
}

void printReversed() {
    printf("Reversed string: ");
    while (top1 != -1) {
        printf("%c", stack1[top1--]);
    }
    printf("\n");
}

int main() {
    char str[MAX];
    int i = 0;

    printf("Enter a string: ");
    fgets(str, MAX, stdin);
    while (str[i] != '\0' && str[i] != '\n') {
        push1(str[i]);
        i++;
    }
        printReversed();
    
        return 0;
    }