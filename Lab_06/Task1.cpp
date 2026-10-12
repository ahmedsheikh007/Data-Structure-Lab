#include <iostream>
#include <string>

using namespace std;

#define MAX_SIZE 100

class BrowserHistoryStack {
private:
    string stackArray[MAX_SIZE];
    int topIndex;

public:
    BrowserHistoryStack() {
        topIndex = -1;
    }

    bool isFull() {
        return topIndex == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return topIndex == -1;
    }

    void push(string page) {
        if (isFull()) {
            cout << "History full! Cannot add more pages.\n";
            return;
        }
        stackArray[++topIndex] = page;
        cout << "Visited: " << page << "\n";
    }

    string pop() {
        if (isEmpty()) {
            cout << "No pages to go back to.\n";
            return "";
        }
        return stackArray[topIndex--];
    }

    string peek() {
        if (isEmpty()) {
            return "No page currently open.";
        }
        return stackArray[topIndex];
    }

    void display() {
        if (isEmpty()) {
            cout << "[Stack is Empty]\n";
            return;
        }
        for (int i = topIndex; i >= 0; i--) {
            cout << "  - " << stackArray[i] << "\n";
        }
    }
};

int main() {
    BrowserHistoryStack history;

    cout << "=== Task 1: Browser History Simulation ===\n\n";

    cout << "1. Visiting Pages:\n";
    history.push("Google");
    history.push("YouTube");
    history.push("Facebook");
    history.push("GitHub");

    cout << "\n2. Full Browsing History (TOP to Bottom):\n";
    history.display();

    cout << "\n3. Pressing Back Button...\n";
    string removedPage = history.pop();
    cout << "   Popped Page (Removed): " << removedPage << "\n";

    cout << "\n4. Current Top Page:\n";
    cout << "   - " << history.peek() << "\n";

    cout << "\n5. Remaining Browsing History:\n";
    history.display();

    return 0;
}
