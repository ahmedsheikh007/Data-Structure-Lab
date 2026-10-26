#include <iostream>
using namespace std;
 
class Node {
public:
    int id;
    Node *left, *right;
    Node(int value) : id(value), left(nullptr), right(nullptr) {}
};
 
class BST {
    Node* root;
 
    Node* insert(Node* node, int value) {
        if (!node) return new Node(value);
        if (value < node->id) node->left = insert(node->left, value);
        else if (value > node->id) node->right = insert(node->right, value);
        return node;
    }
 
    Node* minimum(Node* node) {
        while (node && node->left) node = node->left;
        return node;
    }
 
    Node* remove(Node* node, int value) {
        if (!node) return nullptr;
        if (value < node->id) node->left = remove(node->left, value);
        else if (value > node->id) node->right = remove(node->right, value);
        else {
            if (!node->left) {
                Node* rightChild = node->right;
                delete node;
                return rightChild;
            }
            if (!node->right) {
                Node* leftChild = node->left;
                delete node;
                return leftChild;
            }
            Node* successor = minimum(node->right);
            node->id = successor->id;
            node->right = remove(node->right, successor->id);
        }
        return node;
    }
 
    void inorder(Node* node) {
        if (!node) return;
        inorder(node->left); cout << node->id << " "; inorder(node->right);
    }
    void clear(Node* node) {
        if (!node) return;
        clear(node->left); clear(node->right); delete node;
    }
 
public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }
    void insert(int value) { root = insert(root, value); }
    void deleteID(int value) { root = remove(root, value); }
    void display() { inorder(root); cout << endl; }
};
 
int main() {
    BST tree;
    int ids[] = {50, 30, 70, 20, 40, 60, 80};
    for (int id : ids) tree.insert(id);
 
    int target;
    cout << "Initial IDs: "; tree.display();
    cout << "Enter employee ID to delete: ";
    cin >> target;
    tree.deleteID(target);
    cout << "IDs after deletion: "; tree.display();
    cout << "Test separately with 20 (leaf), 30 (two children), "
         << "and 60 (one child after deleting 50 or adjusting the tree).\n";
    return 0;
}