#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string patientID;
    Node* next;

    Node(string id) {
        patientID = id;
        next = NULL;
    }
};

class LinkedListStack {
private:
    Node* topNode;

public:
    LinkedListStack() {
        topNode = NULL;
    }

    bool isEmpty() {
        return topNode == NULL;
    }

    void push(string id) {
        Node* newNode = new Node(id);
        newNode->next = topNode;
        topNode = newNode;
        cout << "Received Request: " << id << "\n";
    }

    string pop() {
        if (isEmpty()) {
            cout << "No requests to handle.\n";
            return "";
        }
        Node* temp = topNode;
        string handledID = temp->patientID;
        topNode = topNode->next;
        delete temp;
        return handledID;
    }

    string peek() {
        if (isEmpty()) {
            return "No pending requests.";
        }
        return topNode->patientID;
    }

    void display() {
        if (isEmpty()) {
            cout << "[Stack is Empty]\n";
            return;
        }
        Node* current = topNode;
        while (current != NULL) {
            cout << "  - " << current->patientID << "\n";
            current = current->next;
        }
    }

    ~LinkedListStack() {
        while (!isEmpty()) {
            pop();
        }
    }
};

int main() {
    LinkedListStack emergencyStack;

    cout << "=== Task 3: Hospital Emergency Requests ===\n\n";

    cout << "1. Receiving Emergency Requests:\n";
    emergencyStack.push("P101");
    emergencyStack.push("P102");
    emergencyStack.push("P103");
    emergencyStack.push("P104");

    cout << "\n2. All Requests (TOP to Bottom):\n";
    emergencyStack.display();

    cout << "\n3. Handling Latest Request...\n";
    string handled = emergencyStack.pop();
    cout << "   Handled Patient Request: " << handled << "\n";

    cout << "\n4. New TOP Request:\n";
    cout << "   - " << emergencyStack.peek() << "\n";

    cout << "\n5. Remaining Emergency Requests:\n";
    emergencyStack.display();

    return 0;
}
