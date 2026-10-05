#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string player;
    Node* next;

    Node(string name) {
        player = name;
        next = NULL;
    }
};

int main() {
    Node* first = NULL;
    Node* last = NULL;

    string players[5] = {
        "Ali",
        "Ahmed",
        "Usman",
        "Hamza",
        "Bilal"
    };

    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(players[i]);

        if (first == NULL) {
            first = last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    last->next = first;

    cout << "Player Turns (One Complete Round):" << endl;

    Node* current = first;

    for (int i = 0; i < 5; i++) {
        cout << "Turn: " << current->player << endl;
        current = current->next;
    }

    cout << "\nAfter the last player, turn returns to: "
         << current->player << endl;

    return 0;
}
