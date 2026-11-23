#include <iostream>
#include <string>
using namespace std;

class Order {
public:
    int orderID;
    string customerName;
    double amount;
    Order *left, *right;

    Order(int id, string name, double a) {
        orderID = id;
        customerName = name;
        amount = a;
        left = NULL;
        right = NULL;
    }
};

class MaxHeap {
    Order* heap[20];
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
            if (heap[index]->amount > heap[parent]->amount) {
                Order* temp = heap[index];
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
            if (left < size && heap[left]->amount > heap[largest]->amount)
                largest = left;
            if (right < size && heap[right]->amount > heap[largest]->amount)
                largest = right;

            if (largest != index) {
                Order* temp = heap[index];
                heap[index] = heap[largest];
                heap[largest] = temp;
                index = largest;
            } else break;
        }
        connectNodes();
    }

public:
    MaxHeap() { size = 0; }

    void insert(int id, string name, double amount) {
        heap[size] = new Order(id, name, amount);
        size++;
        heapifyUp(size - 1);
    }

    void displayHeap() {
        cout << "Orders in Max Heap (Level Order):\n";
        for (int i = 0; i < size; i++)
            cout << "Order " << heap[i]->orderID << " | "
                 << heap[i]->customerName << " | Rs. " << heap[i]->amount << endl;
    }

    double deleteRoot() {
        double deletedAmount = heap[0]->amount;
        delete heap[0];
        heap[0] = heap[size - 1];
        size--;
        if (size > 0) heapifyDown(0);
        connectNodes();
        return deletedAmount;
    }

    void heapSort() {
        double deletedAmounts[20];
        int count = 0;

        while (size > 0)
            deletedAmounts[count++] = deleteRoot();

        cout << "\nOrder amounts in ascending order:\n";
        for (int i = count - 1; i >= 0; i--)
            cout << deletedAmounts[i] << " ";
        cout << endl;
    }

    ~MaxHeap() {
        for (int i = 0; i < size; i++) delete heap[i];
    }
};

int main() {
    MaxHeap orders;

    orders.insert(301, "Ali", 4500);
    orders.insert(302, "Sara", 8200);
    orders.insert(303, "Ahmed", 2500);
    orders.insert(304, "Hina", 6100);
    orders.insert(305, "Bilal", 9900);
    orders.insert(306, "Noor", 3700);

    orders.displayHeap();
    orders.heapSort();

    return 0;
}
