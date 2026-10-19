#include <iostream>
using namespace std;

#define SIZE 5

int queue[SIZE];
int front = -1;
int rear = -1;

void enqueue(int token) {
    if (rear == SIZE - 1) {
        cout << "Overflow: Queue is full! Cannot add token " << token << endl;
        return;
    }
    
    if (front == -1) {
        front = 0; 
    }
    
    rear++;
    queue[rear] = token;
    cout << "Token " << token << " added." << endl;
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Underflow: No customers waiting!" << endl;
        return;
    }
    
    cout << "Serving Customer: " << queue[front] << endl;
    front++;
}


void display() {
    if (front == -1 || front > rear) {
        cout << "Queue is empty." << endl;
        return;
    }
    
    cout << "Waiting Customers: ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}


void count() {
    if (front == -1 || front > rear) {
        cout << "Total waiting customers: 0" << endl;
    } else {
        cout << "Total waiting customers: " << (rear - front + 1) << endl;
    }
}

int main() {

    enqueue(101);
    enqueue(102);
    enqueue(103);

    cout << endl;
    display();
    count();

    cout << endl;
    dequeue();

    cout << endl;
    display();
    count();

    return 0;
}
