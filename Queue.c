#include <stdio.h>
#define MAX 5 

int queue[MAX], front = -1, rear = -1;

void enqueue() {
    int value;
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue more elements.\n");
        return;
    }
    printf("Enter value to enqueue: ");
    scanf("%d", &value);
    if (front == -1) front = 0;  
    queue[++rear] = value;
    printf("%d enqueued to queue.\n", value);
}

void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! No elements to dequeue.\n");
        front = rear = -1;  
        return;
    }
    printf("%d dequeued from queue.\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for (int i = front; i <= rear; i++)
        printf("%d ", queue[i]);
    printf("\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: printf("Exiting program.\n"); return 0;
            default: printf("Invalid choice! Try again.\n");
        }
    }
}
