#include <iostream>
#include <string>
using namespace std;


class Node {
public:
    string patientID;   
    Node* next;

    Node(string id) {
        patientID = id;
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

    void addPatient(string id) {
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
        cout << "Patient added successfully!" << endl;
    }

    void displayPatients() {
        if (head == NULL) {
            cout << "No patients waiting." << endl;
            return;
        }

        Node* temp = head;
        while (temp != NULL) {
            cout << temp->patientID;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }

    void servePatient() {
        if (head == NULL) {
            cout << "No patients to serve." << endl;
            return;
        }

        Node* temp = head;        
        head = head->next;         
        cout << "Patient " << temp->patientID << " is being served." << endl;
        delete temp;           
    }
};

int main() {
    LinkedList list;
    int choice = 0;
    string id;

    while (choice != 4) {
        cout << "\n===== Hospital Patient Queue =====" << endl;
        cout << "1. Add Patient" << endl;
        cout << "2. Display Waiting Patients" << endl;
        cout << "3. Serve First Patient" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cout << "Enter Patient ID: ";
            cin >> id;
            list.addPatient(id);
        }
        else if (choice == 2) {
            cout << "Waiting Patients:" << endl;
            list.displayPatients();
        }
        else if (choice == 3) {
            list.servePatient();
            cout << "Updated Queue:" << endl;
            list.displayPatients();
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
