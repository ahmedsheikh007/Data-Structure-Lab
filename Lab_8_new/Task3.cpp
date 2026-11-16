#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string folder;
    Node *left, *right;

    Node(string name) : folder(name), left(NULL), right(NULL) {}
};

void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->folder << " ";
    inorder(root->right);
}

void preorder(Node* root) {
    if (root == NULL) return;
    cout << root->folder << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->folder << " ";
}

void destroyTree(Node* root) {
    if (root == NULL) return;
    destroyTree(root->left);
    destroyTree(root->right);
    delete root;
}

int main() {
    Node* root = new Node("C_Drive");
    root->left = new Node("Users");
    root->right = new Node("ProgramFiles");
    root->left->left = new Node("Documents");
    root->left->right = new Node("Downloads");
    root->right->left = new Node("VSCode");
    root->right->right = new Node("Git");

    cout << "Computer File Explorer - DFS Traversals\n\n";

    cout << "In-order Traversal (Visiting Order: Left -> Root -> Right):\n";
    inorder(root);
    cout << "\n\n";

    cout << "Pre-order Traversal (Visiting Order: Root -> Left -> Right):\n";
    preorder(root);
    cout << "\n\n";

    cout << "Post-order Traversal (Visiting Order: Left -> Right -> Root):\n";
    postorder(root);
    cout << endl;

    destroyTree(root);
    return 0;
}
