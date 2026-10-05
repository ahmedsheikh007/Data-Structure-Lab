#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string image;
    Node* prev;
    Node* next;

    Node(string name) {
        image = name;
        prev = NULL;
        next = NULL;
    }
};

int main() {
    Node* first = NULL;
    Node* last = NULL;

    string images[5] = {
        "Nature.jpg",
        "Family.jpg",
        "Vacation.jpg",
        "Sunset.jpg",
        "Mountain.jpg"
    };

    // Add 5 images
    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(images[i]);

        if (first == NULL) {
            first = last = newNode;
        }
        else {
            last->next = newNode;
            newNode->prev = last;
            last = newNode;
        }
    }

    // First -> Last
    cout << "Image Gallery (First -> Last):" << endl;

    Node* current = first;

    while (current != NULL) {
        cout << current->image << endl;
        current = current->next;
    }

    // Last -> First
    cout << "\nImage Gallery (Last -> First):" << endl;

    current = last;

    while (current != NULL) {
        cout << current->image << endl;
        current = current->prev;
    }

    return 0;
}
