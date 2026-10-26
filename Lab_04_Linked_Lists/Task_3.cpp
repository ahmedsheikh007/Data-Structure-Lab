#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string productID;  
    Node* next;

    Node(string id) {
        productID = id;
        next = NULL;
    }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() {
        head = NULL;
    }

    void addProduct(string id) {
        Node* newNode = new Node(id);

        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "Product added to cart!" << endl;
    }

    void displayCart() {
        if (head == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->productID;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void removeProduct(string id) {
        if (head == NULL) {
            cout << "Cart is empty." << endl;
            return;
        }

        if (head->productID == id) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "Product " << id << " removed." << endl;
            return;
        }

        Node* current = head;
        while (current->next != NULL && current->next->productID != id) {
            current = current->next;
        }

        if (current->next == NULL) {
            cout << "Product not found in cart." << endl;
        } else {
            Node* temp = current->next;        
            current->next = temp->next;       
            cout << "Product " << id << " removed." << endl;
        }
    }
};

int main() {
    LinkedList cart;
    int choice = 0;
    string id;

    while (choice != 4) {
        cout << "\n===== Shopping Cart =====" << endl;
        cout << "1. Add Product" << endl;
        cout << "2. Display Cart" << endl;
        cout << "3. Remove Product" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Product ID: ";
            cin >> id;
            cart.addProduct(id);
        }
        else if (choice == 2) {
            cout << "Shopping Cart:" << endl;
            cart.displayCart();
        }
        else if (choice == 3) {
            cout << "Enter Product ID to remove: ";
            cin >> id;
            cart.removeProduct(id);
            cout << "Updated Cart:" << endl;
            cart.displayCart();
        }
        else if (choice == 4) {
            cout << "Program ended." << endl;
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
}
