#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* top = NULL;
void push(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Stack Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = top; 
    top = newNode;       
    printf("%d pushed to stack\n", value);
}
int isEmpty() {
    return top == NULL;
}
int pop() {
    if (isEmpty()) {
        printf("Stack Underflow! The stack is empty.\n");
        return -1; 
    }
    struct Node* temp = top;
    int poppedValue = temp->data;
    top = top->next;     
    free(temp);         
    return poppedValue;
}
int peek() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return -1;
    }
    return top->data;
}

void display() {
    if (isEmpty()) {
        printf("Stack is empty.\n");
        return;
    }
    struct Node* temp = top;
    printf("Stack elements (Top -> Bottom): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    printf("Pushing elements: 10, 20, 30\n");
    push(10);
    push(20);
    push(30);
    display();
    printf("Top element (peek): %d\n", peek());
    printf("Popped element: %d\n", pop());
    display();
    printf("Is stack empty? %s\n", isEmpty() ? "Yes" : "No");
    return 0;
}
