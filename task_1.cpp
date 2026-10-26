#include <iostream>
#include <string>
using namespace std;
 
class Node {
public:
    string name;
    Node *left, *right;
 
    Node(string person) : name(person), left(nullptr), right(nullptr) {}
};
 
void display(Node* root) {
    if (root == nullptr) return;
    cout << root->name << " | Left: ";
    if (root->left) cout << root->left->name;
    else cout << "None";
    cout << " | Right: ";
    if (root->right) cout << root->right->name;
    else cout << "None";
    cout << endl;
    display(root->left);
    display(root->right);
}
 
void destroyTree(Node* root) {
    if (!root) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}
 
int main() {
    Node* grandparent = new Node("Ahmed");
    grandparent->left = new Node("Sara");
    grandparent->right = new Node("Bilal");
    grandparent->left->left = new Node("Ayesha");
    grandparent->left->right = new Node("Hamza");
    grandparent->right->left = new Node("Zain");
    grandparent->right->right = new Node("Noor");
 
    cout << "Family Tree (Person | Left Child | Right Child)\n";
    display(grandparent);
    destroyTree(grandparent);
    return 0;
}