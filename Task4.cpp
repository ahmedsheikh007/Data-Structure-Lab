#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Node {
public:
    int token;
    Node *left, *right;
    int height;

    Node(int val) : token(val), left(NULL), right(NULL), height(1) {}
};

class AVLTree {
    Node* root;

    int getHeight(Node* n) {
        return n != NULL ? n->height : 0;
    }

    int getBalance(Node* n) {
        return n != NULL ? getHeight(n->left) - getHeight(n->right) : 0;
    }

    Node* rightRotate(Node* y) {
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = 1 + max(getHeight(y->left), getHeight(y->right));
        x->height = 1 + max(getHeight(x->left), getHeight(x->right));

        return x;
    }

    Node* leftRotate(Node* x) {
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = 1 + max(getHeight(x->left), getHeight(x->right));
        y->height = 1 + max(getHeight(y->left), getHeight(y->right));

        return y;
    }

    Node* insertNode(Node* node, int token) {
        if (node == NULL) return new Node(token);

        if (token < node->token)
            node->left = insertNode(node->left, token);
        else if (token > node->token)
            node->right = insertNode(node->right, token);
        else
            return node;

        node->height = 1 + max(getHeight(node->left), getHeight(node->right));
        int balance = getBalance(node);

        if (balance > 1 && token < node->left->token) {
            cout << "Rotation: LL Case (Right Rotate at " << node->token << ")\n";
            return rightRotate(node);
        }

        if (balance < -1 && token > node->right->token) {
            cout << "Rotation: RR Case (Left Rotate at " << node->token << ")\n";
            return leftRotate(node);
        }

        if (balance > 1 && token > node->left->token) {
            cout << "Rotation: LR Case (Left Rotate at " << node->left->token
                 << ", Right Rotate at " << node->token << ")\n";
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }

        if (balance < -1 && token < node->right->token) {
            cout << "Rotation: RL Case (Right Rotate at " << node->right->token
                 << ", Left Rotate at " << node->token << ")\n";
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    void inorder(Node* node) {
        if (node == NULL) return;
        inorder(node->left);
        cout << node->token << " ";
        inorder(node->right);
    }

    void printStructure(Node* node, string indent, bool isLeft) {
        if (node == NULL) return;
        cout << indent;
        if (indent.empty()) {
            cout << "[Root] ";
        } else {
            cout << (isLeft ? "|-- (L) " : "`-- (R) ");
        }
        cout << node->token << " (Height: " << node->height
             << ", BF: " << getBalance(node) << ")\n";

        printStructure(node->left, indent + (indent.empty() ? "    " : (isLeft ? "|   " : "    ")), true);
        printStructure(node->right, indent + (indent.empty() ? "    " : (isLeft ? "|   " : "    ")), false);
    }

    void clear(Node* node) {
        if (node == NULL) return;
        clear(node->left);
        clear(node->right);
        delete node;
    }

public:
    AVLTree() : root(NULL) {}
    ~AVLTree() { clear(root); }

    void insert(int token) {
        root = insertNode(root, token);
    }

    void displayInorder() {
        inorder(root);
        cout << endl;
    }

    void displayTree() {
        printStructure(root, "", false);
    }
};

int main() {
    AVLTree hospitalTree;
    int tokens[] = {15, 25, 35, 45, 55, 65, 75};

    cout << "Inserting Appointment Tokens: 15, 25, 35, 45, 55, 65, 75\n";
    for (int i = 0; i < 7; i++) {
        hospitalTree.insert(tokens[i]);
    }

    cout << "\nIn-order Traversal (Sorted Tokens): ";
    hospitalTree.displayInorder();

    cout << "\nFinal Balanced AVL Tree Structure:\n";
    hospitalTree.displayTree();

    return 0;
}
