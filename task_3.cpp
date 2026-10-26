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
 
    void clear(Node* node) {
        if (!node) return;
        clear(node->left); clear(node->right); delete node;
    }
 
public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }
    void insert(int value) { root = insert(root, value); }
 
    bool search(int value, int& comparisons) {
        Node* current = root;
        comparisons = 0;
        while (current) {
            comparisons++;
            if (value == current->id) return true;
            current = (value < current->id) ? current->left : current->right;
        }
        return false;
    }
};
 
int main() {
    BST tree;
    int ids[] = {40, 20, 60, 10, 30, 50, 70};
    for (int id : ids) tree.insert(id);
 
    int target, comparisons = 0;
    cout << "Enter book ID to search: ";
    cin >> target;
    if (tree.search(target, comparisons)) cout << "Book Found\n";
    else cout << "Book Not Found\n";
    cout << "Number of comparisons: " << comparisons << endl;
    return 0;
}