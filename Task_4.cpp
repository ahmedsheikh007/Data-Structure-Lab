#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string orderID;
    Node* next;

    Node(string id) {
        orderID = id;
        next = NULL;
    }
};

class OrderLinkedListStack {
private:
    Node* topNode;

public:
    OrderLinkedListStack() {
        topNode = NULL;
    }

    bool isEmpty() {
        return topNode == NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = topNode;
        topNode = newNode;
        cout << "Order Received: " << id << "\n";
    }

    string pop() {
        if (isEmpty()) {
            cout << "No orders left to process.\n";
            return "";
        }
        Node* temp = topNode;
        string processedID = temp->orderID;
        topNode = topNode->next;
        delete temp;
        return processedID;
    }

    string peek() {
        if (isEmpty()) {
            return "No current order.";
        }
        return topNode->orderID;
    }

    void display() {
        if (isEmpty()) {
            cout << "[Stack is Empty]\n";
            return;
        }
        Node* current = topNode;
        while (current != NULL) {
            cout << "  - " << current->orderID << "\n";
            current = current->next;
        }
    }

    ~OrderLinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    OrderLinkedListStack restaurantStack;

    cout << "=== Task 4: Restaurant Order Processing ===\n\n";

    cout << "1. Receiving Restaurant Orders:\n";
    restaurantStack.push("ORD-101");
    restaurantStack.push("ORD-102");
    restaurantStack.push("ORD-103");
    restaurantStack.push("ORD-104");

    cout << "\n2. All Orders in Stack (TOP to Bottom):\n";
    restaurantStack.display();

    cout << "\n3. Processing Top 2 Orders:\n";
    cout << "   Processed Order 1: " << restaurantStack.pop() << "\n";
    cout << "   Processed Order 2: " << restaurantStack.pop() << "\n";

    cout << "\n4. Current TOP Order:\n";
    cout << "   - " << restaurantStack.peek() << "\n";

    cout << "\n5. Remaining Orders in Stack:\n";
    restaurantStack.display();

    cout << "\n6. Checking if Stack is empty:\n";
    if (restaurantStack.isEmpty()) {
        cout << "   Result: Yes, the stack is empty.\n";
    } else {
        cout << "   Result: No, the stack is not empty.\n";
    }

    return 0;
}
