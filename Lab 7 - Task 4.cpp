#include <iostream>
#include "node.h"
using namespace std;

class ShoppingCart {
private:
    node* head;
    node* tail;

public:
    ShoppingCart() {
        head = nullptr;
        tail = nullptr;
    }

    // Add item at the beginning (priority item)
    void addPriorityItem(int id) {
        node* nn = new node;
        nn->data = id;
        nn->next = head;
        head = nn;

        // If the list was empty, tail should also point to the new node
        if (tail == nullptr) {
            tail = nn;
        }

        cout << "Priority item with ID " << id << " added at the beginning." << endl;
    }

    // Add item at the end (normal item)
    void addNormalItem(int id) {
        node* nn = new node;
        nn->data = id;
        nn->next = nullptr;

        if (tail == nullptr) {
            // List is empty
            head = nn;
            tail = nn;
        } else {
            tail->next = nn;
            tail = nn;
        }

        cout << "Normal item with ID " << id << " added at the end." << endl;
    }

    // Add item after a given product ID (related item)
    void addRelatedItem(int key, int id) {
        if (head == nullptr) {
            cout << "Cart is empty. Cannot add related item after " << key << "." << endl;
            return;
        }

        node* temp = head;
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << "Product ID " << key << " not found." << endl;
            return;
        }

        node* nn = new node;
        nn->data = id;
        nn->next = temp->next;
        temp->next = nn;

        // If the related item was added after the tail, update tail
        if (temp == tail) {
            tail = nn;
        }

        cout << "Related item with ID " << id << " added after product ID " << key << "." << endl;
    }

    // Display the shopping cart
    void displayCart() {
        if (head == nullptr) {
            cout << "Shopping cart is empty." << endl;
            return;
        }

        node* temp = head;
        cout << "Shopping Cart Items: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    ShoppingCart cart;
    int choice, id, key;

    while (true) {
        cout << endl;
        cout << "===== Shopping Cart Menu =====" << endl;
        cout << "1. Add Priority Item (Beginning)" << endl;
        cout << "2. Add Normal Item (End)" << endl;
        cout << "3. Add Related Item (After Product ID)" << endl;
        cout << "4. Display Cart" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Product ID: ";
                cin >> id;
                cart.addPriorityItem(id);
                break;

            case 2:
                cout << "Enter Product ID: ";
                cin >> id;
                cart.addNormalItem(id);
                break;

            case 3:
                cout << "Enter Product ID after which to add: ";
                cin >> key;
                cout << "Enter new Product ID: ";
                cin >> id;
                cart.addRelatedItem(key, id);
                break;

            case 4:
                cart.displayCart();
                break;

            case 5:
                cout << "Exiting program." << endl;
                return 0;

            default:
                cout << "Invalid choice. Try again." << endl;
        }
    }
}
