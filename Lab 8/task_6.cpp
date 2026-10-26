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
 
    Node* insertNode(Node* n, int v) {
        if (!n) return new Node(v);
        if (v < n->id) n->left = insertNode(n->left, v);
        else if (v > n->id) n->right = insertNode(n->right, v);
        else cout << "Duplicate product ID. Not inserted.\n";
        return n;
    }
    bool searchNode(Node* n, int v) {
        if (!n) return false;
        if (n->id == v) return true;
        return v < n->id ? searchNode(n->left, v) : searchNode(n->right, v);
    }
    Node* minNode(Node* n) {
        while (n && n->left) n = n->left;
        return n;
    }
    Node* deleteNode(Node* n, int v) {
        if (!n) return nullptr;
        if (v < n->id) n->left = deleteNode(n->left, v);
        else if (v > n->id) n->right = deleteNode(n->right, v);
        else {
            if (!n->left) { Node* r = n->right; delete n; return r; }
            if (!n->right) { Node* l = n->left; delete n; return l; }
            Node* successor = minNode(n->right);
            n->id = successor->id;
            n->right = deleteNode(n->right, successor->id);
        }
        return n;
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
    void insert(int v) { root = insertNode(root, v); }
    bool search(int v) { return searchNode(root, v); }
    void remove(int v) {
        if (!search(v)) { cout << "Product ID not found.\n"; return; }
        root = deleteNode(root, v);
        cout << "Product deleted successfully.\n";
    }
    void showInorder() { inorder(root); cout << endl; }
    void showPreorder() { preorder(root); cout << endl; }
    void showPostorder() { postorder(root); cout << endl; }
};
 
int main() {
    BST tree;
    int choice, id;
    do {
        cout << "\n--- Online Store Inventory ---\n"
             << "1. Insert product ID\n2. Search product ID\n"
             << "3. Delete product ID\n4. Display in-order\n"
             << "5. Display pre-order\n6. Display post-order\n7. Exit\n"
             << "Enter choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            cout << "Enter product ID: "; cin >> id; tree.insert(id); break;
        case 2:
            cout << "Enter product ID: "; cin >> id;
            cout << (tree.search(id) ? "Product Found\n" : "Product Not Found\n");
            break;
        case 3:
            cout << "Enter product ID: "; cin >> id; tree.remove(id); break;
        case 4: cout << "In-order: "; tree.showInorder(); break;
        case 5: cout << "Pre-order: "; tree.showPreorder(); break;
        case 6: cout << "Post-order: "; tree.showPostorder(); break;
        case 7: cout << "Exiting program.\n"; break;
        default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 7);
    return 0;
}