#include <iostream>
#include <string>
using namespace std;

class Patient {
public:
    string name;
    int patientID, priority;
    Patient *left, *right;

    Patient(string n, int id, int p) {
        name = n;
        patientID = id;
        priority = p;
        left = NULL;
        right = NULL;
    }
};

class MaxHeap {
    Patient* heap[20];
    int size;

    void connectNodes() {
        for (int i = 0; i < size; i++) {
            heap[i]->left = (2 * i + 1 < size) ? heap[2 * i + 1] : NULL;
            heap[i]->right = (2 * i + 2 < size) ? heap[2 * i + 2] : NULL;
        }
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index]->priority > heap[parent]->priority) {
                Patient* temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else break;
        }
        connectNodes();
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            int left = 2 * index + 1, right = 2 * index + 2;
            if (left < size && heap[left]->priority > heap[largest]->priority)
                largest = left;
            if (right < size && heap[right]->priority > heap[largest]->priority)
                largest = right;

            if (largest != index) {
                Patient* temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;
                index = largest;
            } else break;
        }
        connectNodes();
    }

public:
    MaxHeap() { size = 0; }

    void insert(string name, int id, int priority) {
        heap[size] = new Patient(name, id, priority);
        size++;
        heapifyUp(size - 1);
    }

    void display() {
        cout << "Patients in Heap (Level Order):\n";
        for (int i = 0; i < size; i++)
            cout << heap[i]->name << " | ID: " << heap[i]->patientID
                 << " | Priority: " << heap[i]->priority << endl;
    }

    void treatPatient() {
        if (size == 0) {
            cout << "No patients available.\n";
            return;
        }

        cout << "\nPatient treated: " << heap[0]->name
             << " (Priority " << heap[0]->priority << ")\n";
        delete heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0) heapifyDown(0);
        connectNodes();
    }

    void nextPatient() {
        if (size > 0)
            cout << "Next patient: " << heap[0]->name
                 << " (Priority " << heap[0]->priority << ")\n";
    }

    ~MaxHeap() {
        for (int i = 0; i < size; i++) delete heap[i];
    }
};

int main() {
    MaxHeap hospital;

    hospital.insert("Usman", 201, 3);
    hospital.insert("Fatima", 202, 5);
    hospital.insert("Zain", 203, 2);
    hospital.insert("Noor", 204, 4);
    hospital.insert("Hamza", 205, 1);
    hospital.insert("Maryam", 206, 5);

    hospital.display();
    cout << "\nHighest priority patient: ";
    hospital.nextPatient();
    hospital.treatPatient();

    cout << "\nUpdated Heap:\n";
    hospital.display();
    hospital.nextPatient();

    return 0;
}
