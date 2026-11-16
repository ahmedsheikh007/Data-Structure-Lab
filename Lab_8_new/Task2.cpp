#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Node {
public:
    string category;
    Node *left, *right;

    Node(string cat) : category(cat), left(NULL), right(NULL) {}
};

void bfsTraversal(Node* root) {
    if (root == NULL) return;

    queue<Node*> q;
    q.push(root);

    int level = 0;
    cout << "Level-by-Level Category Exploration:\n";
    while (!q.empty()) {
        int levelSize = q.size();
        cout << "Level " << level << ": ";
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();

            cout << current->category;
            if (i < levelSize - 1) cout << ", ";

            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
        cout << endl;
        level++;
    }

    q.push(root);
    cout << "\nBFS Traversal Order: ";
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        cout << current->category;
        if (current->left != NULL) q.push(current->left);
        if (current->right != NULL) q.push(current->right);
        if (!q.empty()) cout << " -> ";
    }
    cout << endl;
}

void destroyTree(Node* root) {
    if (root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    Node* root = new Node("Online Store");
    root->left = new Node("Electronics");
    root->right = new Node("Clothing");
    root->left->left = new Node("Mobiles");
    root->left->right = new Node("Laptops");
    root->right->left = new Node("Men");
    root->right->right = new Node("Women");
    root->left->left->left = new Node("Accessories");

    bfsTraversal(root);

    destroyTree(root);
    return 0;
}
