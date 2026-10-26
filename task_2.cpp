#include <iostream>
using namespace std;
 
class Node {
public:
    int roll;
    Node *left, *right;
    Node(int value) : roll(value), left(nullptr), right(nullptr) {}
};
 
class BST {
    Node* root;
 
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->roll) node->left = insert(node->left, value);
        else if (value > node->roll) node->right = insert(node->right, value);
        else cout << "Duplicate roll number ignored: " << value << endl;
        return node;
    }
 
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left);
        cout << node->roll << " ";
        inorder(node->right);
    }
 
    void clear(Node* node) {
        if (!node) return;
        clear(node->left); clear(node->right); delete node;
    }
 
public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }
    void insert(int value) { root = insert(root, value); }
    void displayAscending() { inorder(root); cout << endl; }
};
 
int main() {
    BST tree;
    int value;
    int initial[] = {45, 25, 65, 15, 35, 55, 75};
    for (int roll : initial) tree.insert(roll);
 
    cout << "Enter two additional roll numbers: ";
    cin >> value; tree.insert(value);
    cin >> value; tree.insert(value);
 
    cout << "Roll numbers in ascending order: ";
    tree.displayAscending();
    return 0;
}