#include <stdio.h>
#define SIZE 5

int main() {
    int queue[SIZE];
    int front = -1, rear = -1;
    int choice, element;

    while (1) {
        printf("\n Circular Queue Menu \n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if ((front == 0 && rear == SIZE - 1) || (rear + 1) % SIZE == front) {
                    printf("Queue is full\n");
                } else {
                    printf("Enter the element to enqueue: ");
                    scanf("%d", &element);
                    if (front == -1) {
                        front = rear = 0;
                    } else {
                        rear = (rear + 1) % SIZE;
                    }
                    queue[rear] = element;
                    printf("Enqueued: %d\n", element);
                }
                break;

            case 2: 
                if (front == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Dequeued: %d\n", queue[front]);
                    if (front == rear) {
                        front = rear = -1; 
                    } else {
                        front = (front + 1) % SIZE;
                    }
                }
                break;

                case 3: 
                if (front == -1) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue elements:\n");
                   
                    int i = front;
                    while (1) {
                        printf("Queue[%d]=%d\n", i, queue[i]);
                        if (i == rear)
                            break;
                        i = (i + 1) % SIZE;
                    }
                }
                break;
            

            case 4: 
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}


