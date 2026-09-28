#include <iostream>
using namespace std;


class Node {
public:
    int rollNo;    
    Node* next;    

    Node(int roll) {
        rollNo = roll;
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


    void addStudent(int roll) {
        Node* newNode = new Node(roll);

        if (head == NULL) {

            head = newNode;
        } else {
            
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;  
        }
        cout << "Student added successfully!" << endl;
    }

    void displayStudents() {
        if (head == NULL) {
            cout << "No students registered yet." << endl;
            return;
        }

        cout << "Registered Students:" << endl;
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->rollNo;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void searchStudent(int roll) {
        Node* temp = head;
        while (temp != NULL) {
            if (temp->rollNo == roll) {
                cout << "Student Found" << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "Student Not Found" << endl;
    }
};

int main() {
    LinkedList list;   
    int choice = 0, roll;

    while (choice != 4) {
        cout << "\n===== Workshop Registration =====" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Display Students" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Roll Number: ";
            cin >> roll;
            list.addStudent(roll);
        }
        else if (choice == 2) {
            list.displayStudents();
        }
        else if (choice == 3) {
            cout << "Enter Roll Number to Search: ";
            cin >> roll;
            list.searchStudent(roll);
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
