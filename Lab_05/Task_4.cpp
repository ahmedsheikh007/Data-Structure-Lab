#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;

    Node(string name) {
        song = name;
        next = NULL;
    }
};

int main() {
    Node* first = NULL;
    Node* last = NULL;

    string songs[5] = {
        "Believer",
        "Perfect",
        "Shape of You",
        "Counting Stars",
        "Faded"
    };

    for (int i = 0; i < 5; i++) {
        Node* newNode = new Node(songs[i]);

        if (first == NULL) {
            first = last = newNode;
        }
        else {
            last->next = newNode;
            last = newNode;
        }
    }

    last->next = first;

    cout << "Music Playlist (One Complete Round):" << endl;

    Node* current = first;

    for (int i = 0; i < 5; i++) {
        cout << current->song << endl;
        current = current->next;
    }

    cout << "\nPlaying Playlist for 2 Complete Rounds:" << endl;

    current = first;

    for (int i = 0; i < 10; i++) {
        cout << "Playing: " << current->song << endl;
        current = current->next;
    }

    return 0;
}
