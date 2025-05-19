#include <stdio.h>
#define SIZE 5

int queue[SIZE], front = -1, rear = -1;

void enqueue(int val) {
    if (rear == SIZE - 1)
        printf("Queue Full\n");
    else {
        if (front == -1) front = 0;
        queue[++rear] = val;
    }
}
void dequeue() {
    if (front == -1 || front > rear)
        printf("Queue Empty\n");
    else
        printf("Deleted: %d\n", queue[front++]);
}

void display() {
    if (front == -1 || front > rear)
        printf("Queue Empty\n");
    else {
        printf("Queue Elements:\n");
        for (int i = front; i <= rear; i++)
            printf("a[%d] = %d\n", i, queue[i]);
    }
}

int main() {
    int ch, val;
    do {
        printf("\n1.Enqueue 2.Dequeue 3.Display 4.Exit\nChoice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &val);
                enqueue(val);
                break;
            case 2: dequeue(); break;
            case 3: display(); break;
        }
    } while (ch != 4);
    return 0;
}
