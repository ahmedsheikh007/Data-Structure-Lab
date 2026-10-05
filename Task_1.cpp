#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string website;
    Node* prev;
    Node* next;

    Node(string name) {
        website = name;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    Node* first = NULL;
    Node* last = NULL ;

    string websites[5] = {
        "Google",
        "YouTube",
        "GitHub",
        "Wikipedia",
        "StackOverflow"
    };

    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(websites[i]);

        if (first == NULL) {
            first = last = newNode;
        } else {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }

    cout << "Browser History (First -> Last):" << endl;

    Node* current = first;

    while (current != NULL) {
        cout << current->website << endl;
        current = current->next;
    }

    cout << "\nBrowser History (Last -> First):" << endl;

    current = last;

    while (current != NULL) {
        cout << current->website << endl;
        current = current->prev;
    }

    return 0;
}
