#include <iostream>
using namespace std;

#define SIZE 5

int buffer[SIZE];
int front = -1;
int rear = -1;

bool isFull() {
    return (rear + 1) % SIZE == front;
}

bool isEmpty() {
    return front == -1;
}

void enqueue(int packetID) {
    if (isFull()) {
        cout << "Overflow: Buffer full! Cannot add Packet " << packetID << endl;
        return;
    }

    if (isEmpty()) {
        front = 0;
        rear = 0;
    } else {
        rear = (rear + 1) % SIZE; 
    }

    buffer[rear] = packetID;
    cout << "Packet " << packetID << " stored in buffer." << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Underflow: Buffer empty! No packets to transmit." << endl;
        return;
    }

    cout << "Transmitting Packet: " << buffer[front] << endl;

    if (front == rear) {

        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % SIZE; 
    }
}

void display() {
    if (isEmpty()) {
        cout << "Buffer is empty." << endl;
        return;
    }

    cout << "Waiting Packets: ";
    int i = front;
    while (true) {
        cout << "[" << buffer[i] << "] ";
        if (i == rear) break;
        i = (i + 1) % SIZE; 
    }
    cout << endl;
}

int main() {

    cout << "--- Packets Arrive ---" << endl;
    enqueue(201);
    enqueue(202);
    enqueue(203);
    enqueue(204);
    enqueue(205); 

    cout << endl;
    display();


    cout << "\n--- Transmitting Packets ---" << endl;
    dequeue(); 
    dequeue(); 

    cout << endl;
    display();


    cout << "\n--- Reusing Emptied Positions ---" << endl;
    enqueue(206); 
    enqueue(207); 

    cout << endl;
    display();


    cout << "\n--- Checking Overflow ---" << endl;
    enqueue(208);

    return 0;
}
