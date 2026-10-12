#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 100

class ActionStack {
private:
    string actions[MAX_SIZE];
    int topIndex;

public:
    ActionStack() {
        topIndex = -1;
    }

    bool isFull() {
        return topIndex == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(string action) {
        if (isFull()) {
            cout << "Action memory full!\n";
            return;
        }
        actions[++topIndex] = action;
        cout << "Performed: " << action << "\n";
    }

    string pop() {
        if (isEmpty()) {
            cout << "Nothing to undo.\n";
            return "";
        }
        return actions[topIndex--];
    }

    string peek() {
        if (isEmpty()) {
            return "No actions remaining.";
        }
        return actions[topIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "[Stack is Empty]\n";
            return;
        }
        for (int i = topIndex; i >= 0; i--) {
            cout << "  - " << actions[i] << "\n";
        }
    }
};

int main() {
    ActionStack editorHistory;

    cout << "=== Task 2: Text Editor Undo Simulation ===\n\n";

    cout << "1. User Actions Performed:\n";
    editorHistory.push("Type \"Hello\"");
    editorHistory.push("Type \"World\"");
    editorHistory.push("Add \"!\"");
    editorHistory.push("Delete \"!\"");

    cout << "\n2. All Action History (TOP to Bottom):\n";
    editorHistory.display();

    cout << "\n3. Performing 2 Undo Operations:\n";
    cout << "   Undone Action 1: " << editorHistory.pop() << "\n";
    cout << "   Undone Action 2: " << editorHistory.pop() << "\n";

    cout << "\n4. Current Top Action:\n";
    cout << "   - " << editorHistory.peek() << "\n";

    cout << "\n5. Remaining Actions in History:\n";
    editorHistory.display();

    return 0;
}
