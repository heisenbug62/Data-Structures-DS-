#include <iostream>
using namespace std;

struct node {
    int rollNo;
    node* next;
};

class LL {
private:
    node* head;

public:
    LL() {
        head = nullptr;
    }

    // Insert at the beginning
    void insertAtBeginning(int rollNo) {
        node* nn = new node;
        nn->rollNo = rollNo;
        nn->next = head;
        head = nn;
        cout << "Inserted " << rollNo << " at the beginning." << endl;
    }

    // Insert at the end
    void insertAtEnd(int rollNo) {
        node* nn = new node;
        nn->rollNo = rollNo;
        nn->next = nullptr;

        if (head == nullptr) {
            head = nn;
        } else {
            node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = nn;
        }
        cout << "Inserted " << rollNo << " at the end." << endl;
    }

    // Insert after a given roll number
    void insertAfter(int key, int rollNo) {
        if (head == nullptr) {
            cout << "List is empty. Cannot insert after " << key << "." << endl;
            return;
        }

        node* temp = head;
        while (temp != nullptr && temp->rollNo != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Roll number " << key << " not found." << endl;
            return;
        }

        node* nn = new node;
        nn->rollNo = rollNo;
        nn->next = temp->next;
        temp->next = nn;

        cout << "Inserted " << rollNo << " after " << key << "." << endl;
    }

    void display() {
        if (head == nullptr) {
            cout << "List is empty." << endl;
            return;
        }

        node* temp = head;
        cout << "Student Roll Numbers: ";
        while (temp != nullptr) {
            cout << temp->rollNo << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LL list;
    int choice, rollNo, key;

    while (true) {
        cout << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Insert After a Roll Number" << endl;
        cout << "4. Display List" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            list.insertAtBeginning(rollNo);
            break;

        case 2:
            cout << "Enter Roll Number: ";
            cin >> rollNo;
            list.insertAtEnd(rollNo);
            break;

        case 3:
            cout << "Enter the Roll Number after which to insert: ";
            cin >> key;
            cout << "Enter new Roll Number: ";
            cin >> rollNo;
            list.insertAfter(key, rollNo);
            break;

        case 4:
            list.display();
            break;

        case 5:
            cout << "Exiting program." << endl;
            return 0;

        default:
            cout << "Invalid choice. Try again." << endl;
        }
    }
}
