#include <iostream>
using namespace std;

#define SIZE 5

int deque[SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return (front == 0 && rear == SIZE - 1) || (front == rear + 1);
}

bool isEmpty() {
    return front == -1;
}


void insertFront(int requestID) {
    if (isFull()) {
        cout << "Overflow: Deque is full! Cannot insert " << requestID << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (front == 0) {
        front = SIZE - 1; // Wrap around to end
    } else {
        front--;
    }

    deque[front] = requestID;
    cout << "Inserted request " << requestID << " at front." << endl;
}

void insertRear(int requestID) {
    if (isFull()) {
        cout << "Overflow: Deque is full! Cannot insert " << requestID << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else if (rear == SIZE - 1) {
        rear = 0; // Wrap around to beginning
    } else {
        rear++;
    }

    deque[rear] = requestID;
    cout << "Inserted request " << requestID << " at rear." << endl;
}


void deleteFront() {
    if (isEmpty()) {
        cout << "Underflow: Deque is empty!" << endl;
        return;
    }

    cout << "Removed request " << deque[front] << " from front." << endl;

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (front == SIZE - 1) {
        front = 0;
    } else {
        front++;
    }
}


void deleteRear() {
    if (isEmpty()) {
        cout << "Underflow: Deque is empty!" << endl;
        return;
    }

    cout << "Removed request " << deque[rear] << " from rear." << endl;

    if (front == rear) {
        front = -1;
        rear = -1;
    } else if (rear == 0) {
        rear = SIZE - 1;
    } else {
        rear--;
    }
}


void display() {
    if (isEmpty()) {
        cout << "Deque is empty." << endl;
        return;
    }

    cout << "Front -> ";
    int i = front;
    while (true) {
        cout << deque[i] << " ";
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    cout << "<- Rear" << endl;
}

int main() {

    insertRear(301);
    insertRear(302);
    insertFront(300);

    cout << endl;
    display(); 

    cout << endl;
    deleteFront(); 

    cout << endl;
    display();

    cout << endl;
    deleteRear(); 

    cout << endl;
    display();

    return 0;
}
