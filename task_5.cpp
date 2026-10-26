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
    void inorder(Node* n) {
        if (!n) return; inorder(n->left); cout << n->id << " "; inorder(n->right);
    }
    void preorder(Node* n) {
        if (!n) return; cout << n->id << " "; preorder(n->left); preorder(n->right);
    }
    void postorder(Node* n) {
        if (!n) return; postorder(n->left); postorder(n->right); cout << n->id << " ";
    }
    void clear(Node* n) {
        if (!n) return; clear(n->left); clear(n->right); delete n;
    }
public:
    BST() : root(nullptr) {}
    ~BST() { clear(root); }
    void insert(int value) { root = insert(root, value); }
    void showTraversals() {
        cout << "In-order: "; inorder(root); cout << endl;
        cout << "Pre-order: "; preorder(root); cout << endl;
        cout << "Post-order: "; postorder(root); cout << endl;
    }
};
 
int main() {
    BST tree;
    int ids[] = {40, 20, 60, 10, 30, 50, 70};
    for (int id : ids) tree.insert(id);
    tree.showTraversals();
    cout << "In-order traversal displays IDs in ascending order.\n";
    return 0;
}