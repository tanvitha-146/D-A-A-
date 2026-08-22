#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Node* front = NULL;
struct Node* rear = NULL;
int isEmpty() {
    return front == NULL;
}
void enqueue(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Queue Overflow! Memory allocation failed.\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode; // Link old rear to the new node
        rear = newNode;       // Update rear to point to the new node
    }
    printf("%d enqueued to queue\n", value);
}

int dequeue() {
    if (isEmpty()) {
        printf("Queue Underflow! The queue is empty.\n");
        return -1;
    }
    struct Node* temp = front;
    int dequeuedValue = temp->data;
    front = front->next; // Move front pointer to the next node
    if (front == NULL) {
        rear = NULL;
    }
    free(temp); 
    return dequeuedValue;
}
int peek() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return -1;
    }
    return front->data;
}
void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = front;
    printf("Queue elements (Front -> Rear): ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    printf("Enqueuing elements: 10, 20, 30\n");
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();
    printf("Front element (peek): %d\n", peek());
    printf("Dequeued element: %d\n", dequeue());
    display();
    printf("Enqueuing element: 40\n");
    enqueue(40);
    display();
    printf("Is queue empty? %s\n", isEmpty() ? "Yes" : "No");
    return 0;
}
