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


    void addAtEnd(int roll) {
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
        cout << "Student added at the end!" << endl;
    }


    void insertAtBeginning(int roll) {
        Node* newNode = new Node(roll);
        newNode->next = head;   
        head = newNode;        
        cout << "Student inserted at the beginning!" << endl;
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

    void displayStudents() {
        if (head == NULL) {
            cout << "No students enrolled." << endl;
            return;
        }

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
};

int main() {
    LinkedList list;
    int choice = 0, roll;

    while (choice != 5) {
        cout << "\n===== Course Enrollment =====" << endl;
        cout << "1. Add Student at End" << endl;
        cout << "2. Insert Student at Beginning" << endl;
        cout << "3. Search Student" << endl;
        cout << "4. Display Students" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Roll Number: ";
            cin >> roll;
            list.addAtEnd(roll);
        }
        else if (choice == 2) {
            cout << "Enter Roll Number: ";
            cin >> roll;
            list.insertAtBeginning(roll);
        }
        else if (choice == 3) {
            cout << "Enter Roll Number to Search: ";
            cin >> roll;
            list.searchStudent(roll);
        }
        else if (choice == 4) {
            cout << "Enrolled Students:" << endl;
            list.displayStudents();
        }
        else if (choice == 5) {
            cout << "Program ended." << endl;
        }
        else {
            cout << "Invalid choice, try again." << endl;
        }
    }

    return 0;
}
