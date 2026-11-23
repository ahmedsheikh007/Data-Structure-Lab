#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Student {
public:
    string name;
    int rollNo, marks;
    Student *left, *right;

    Student(string n, int r, int m) {
        name = n;
        rollNo = r;
        marks = m;
        left = NULL;
        right = NULL;
    }
};

class MaxHeap {
    Student* heap[20];
    int size;

    void connectNodes() {
        for (int i = 0; i < size; i++) {
            if (2 * i + 1 < size)
                heap[i]->left = heap[2 * i + 1];
            else
                heap[i]->left = NULL;

            if (2 * i + 2 < size)
                heap[i]->right = heap[2 * i + 2];
            else
                heap[i]->right = NULL;
        }
    }

    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1) / 2;
            if (heap[index]->marks > heap[parent]->marks) {
                Student* temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else {
                break;
            }
        }
        connectNodes();
    }

    void heapifyDown(int index) {
        while (true) {
            int largest = index;
            int left = 2 * index + 1;
            int right = 2 * index + 2;

            if (left < size && heap[left]->marks > heap[largest]->marks)
                largest = left;
            if (right < size && heap[right]->marks > heap[largest]->marks)
                largest = right;

            if (largest != index) {
                Student* temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;
                index = largest;
            } else {
                break;
            }
        }
        connectNodes();
    }

public:
    MaxHeap() { size = 0; }

    void insert(string name, int roll, int marks) {
        heap[size] = new Student(name, roll, marks);
        size++;
        heapifyUp(size - 1);
    }

    void display() {
        cout << "Student Heap (Level Order):\n";
        for (int i = 0; i < size; i++)
            cout << heap[i]->name << " | Roll: " << heap[i]->rollNo
                 << " | Marks: " << heap[i]->marks << endl;
    }

    void deleteHighest() {
        if (size == 0) {
            cout << "Heap is empty.\n";
            return;
        }

        cout << "\nDeleted highest merit student: " << heap[0]->name
             << " (" << heap[0]->marks << " marks)\n";
        delete heap[0];

        heap[0] = heap[size - 1];
        size--;
        if (size > 0)
            heapifyDown(0);
        connectNodes();
    }

    ~MaxHeap() {
        for (int i = 0; i < size; i++)
            delete heap[i];
    }
};

int main() {
    MaxHeap students;

    students.insert("Ali", 101, 85);
    students.insert("Sara", 102, 92);
    students.insert("Ahmed", 103, 78);
    students.insert("Ayesha", 104, 95);
    students.insert("Bilal", 105, 88);
    students.insert("Hina", 106, 81);

    students.display();
    students.deleteHighest();
}

