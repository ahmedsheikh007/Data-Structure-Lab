#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string name;
    Node *left, *right;

    Node(string member) : name(member), left(NULL), right(NULL) {}
};

void display(Node* root) {
    if (root == NULL) return;

    cout << root->name << " | Left: ";
    if (root->left != NULL) cout << root->left->name;
    else cout << "None";

    cout << " | Right: ";
    if (root->right != NULL) cout << root->right->name;
    else cout << "None";

    cout << endl;

    display(root->left);
    display(root->right);
}

void destroyTree(Node* root) {
    if (root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    Node* hod = new Node("Dr. Tariq (HOD)");
    hod->left = new Node("Dr. Ayesha (Coord-1)");
    hod->right = new Node("Prof. Bilal (Coord-2)");
    hod->left->left = new Node("Lec. Sara");
    hod->left->right = new Node("Lec. Hamza");
    hod->right->left = new Node("Lec. Zain");
    hod->right->right = new Node("Lec. Noor");

    cout << "University Department Hierarchy (Member | Left Child | Right Child)\n";
    display(hod);

    destroyTree(hod);
    return 0;
}
