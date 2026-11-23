#include <iostream>
#include <string>
using namespace std;

class Medicine {
public:
    string name;
    int medicineID, expiryDate;
    Medicine *left, *right;

    Medicine(string n, int id, int date) {
        name = n;
        medicineID = id;
        expiryDate = date;
        left = NULL;
        right = NULL;
    }
};

class MinHeap {
    Medicine* heap[20];
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
            if (heap[index]->expiryDate < heap[parent]->expiryDate) {
                Medicine* temp = heap[index];
                heap[index] = heap[parent];
                heap[parent] = temp;
                index = parent;
            } else break;
        }
        connectNodes();
    }

    void heapifyDown(int index) {
        while (true) {
            int smallest = index;
            int left = 2 * index + 1, right = 2 * index + 2;
            if (left < size && heap[left]->expiryDate < heap[smallest]->expiryDate)
                smallest = left;
            if (right < size && heap[right]->expiryDate < heap[smallest]->expiryDate)
                smallest = right;

            if (smallest != index) {
                Medicine* temp = heap[index];
                heap[index] = heap[smallest];
                heap[smallest] = temp;
                index = smallest;
            } else break;
        }
        connectNodes();
    }

public:
    MinHeap() { size = 0; }

    void insert(string name, int id, int date) {
        heap[size] = new Medicine(name, id, date);
        size++;
        heapifyUp(size - 1);
    }

    void display() {
        cout << "Medicines in Min Heap (Level Order):\n";
        for (int i = 0; i < size; i++)
            cout << heap[i]->name << " | ID: " << heap[i]->medicineID
                 << " | Expiry: " << heap[i]->expiryDate << endl;
    }

    void deleteNearestExpiry() {
        if (size == 0) return;
        cout << "\nMedicine with nearest expiry: " << heap[0]->name
             << " (" << heap[0]->expiryDate << ")\n";
        delete heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0) heapifyDown(0);
        connectNodes();
    }

    ~MinHeap() {
        for (int i = 0; i < size; i++) delete heap[i];
    }
};

int main() {
    MinHeap store;

    store.insert("Panadol", 401, 20261215);
    store.insert("Brufen", 402, 20261130);
    store.insert("Augmentin", 403, 20270310);
    store.insert("Calpol", 404, 20261205);
    store.insert("Disprin", 405, 20261125);
    store.insert("ORS", 406, 20270420);

    store.display();
    store.deleteNearestExpiry();

    cout << "\nUpdated Heap:\n";
    store.display();

    return 0;
}
