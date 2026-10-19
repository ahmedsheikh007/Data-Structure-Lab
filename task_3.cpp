#include <iostream>
#include <string>
using namespace std;

#define SIZE 5

struct Patient {
    string id;
    int priority;
};

Patient queue[SIZE];
int totalPatients = 0;

bool isFull() {
    return totalPatients == SIZE;
}

bool isEmpty() {
    return totalPatients == 0;
}

void enqueue(string id, int priority) {
    if (isFull()) {
        cout << "Overflow: Emergency queue full! Cannot add patient " << id << endl;
        return;
    }

    int i;
    for (i = totalPatients - 1; (i >= 0 && queue[i].priority > priority); i--) {
        queue[i + 1] = queue[i];
    }

    queue[i + 1].id = id;
    queue[i + 1].priority = priority;
    totalPatients++;

    cout << "Patient " << id << " added with Priority " << priority << endl;
}

void dequeue() {
    if (isEmpty()) {
        cout << "Underflow: No patients waiting for treatment!" << endl;
        return;
    }

    cout << "Treating Patient: " << queue[0].id << " (Priority " << queue[0].priority << ")" << endl;

    for (int i = 0; i < totalPatients - 1; i++) {
        queue[i] = queue[i + 1];
    }
    totalPatients--;
}

void display() {
    if (isEmpty()) {
        cout << "No patients currently in the emergency queue." << endl;
        return;
    }

    cout << "Waiting Patients (Sorted by Urgency):" << endl;
    for (int i = 0; i < totalPatients; i++) {
        cout << " -> Patient ID: " << queue[i].id << " | Priority Level: " << queue[i].priority << endl;
    }
}

int main() {
    enqueue("P101", 3);
    enqueue("P102", 1);
    enqueue("P103", 2);

    cout << endl;
    display();

    cout << endl;
    dequeue();

    cout << endl;
    display();

    cout << endl;
    enqueue("P104", 1);

    cout << endl;
    display();

    return 0;
}
