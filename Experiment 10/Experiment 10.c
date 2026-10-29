#include <stdio.h>
#define SIZE 5

char queue[SIZE];
int front = 0, rear = -1, count = 0;

void transmit(char data) {
    if (count == SIZE) {
        printf("Buffer Full\n");
        return;
    }

    rear = (rear + 1) % SIZE;
    queue[rear] = data;
    count++;

    printf("Transmitted: %c\n", data);
}

void receive() {
    if (count == 0) {
        printf("Buffer Empty\n");
        return;
    }

    printf("Received: %c\n", queue[front]);
    front = (front + 1) % SIZE;
    count--;
}

int main() {
    transmit('A');
    transmit('B');
    transmit('C');

    receive();
    receive();
    receive();

    return 0;
}
