#include <iostream>
using namespace std;

struct Customer
{
    string name;
    string transaction;
};

class Queue
{
protected:
    Customer* arr;
    int front, back;
    int size;
    int count;

public:
    Queue(int s)
    {
        size = s;
        arr = new Customer[s];
        front = -1;
        back = -1;
        count = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isEmpty()
    {
        if (front == -1 && back == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    bool isFull()
    {
        if ((back + 1) % size == front)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(Customer c)
    {
        if (isFull())
        {
            cout << "Queue is Full. Cannot add more customers." << endl;
        }
        else if (isEmpty())
        {
            front = 0;
            back = 0;
            arr[back] = c;
            count++;
        }
        else
        {
            back = (back + 1) % size;
            arr[back] = c;
            count++;
        }
    }

    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty. No customers to serve." << endl;
        }
        else
        {
            cout << "Serving Customer: " << arr[front].name << " | Transaction: " << arr[front].transaction << endl;

            if (front == back)
            {
                front = -1;
                back = -1;
            }
            else
            {
                front = (front + 1) % size;
            }

            count--;
        }
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "No customers waiting." << endl;
        }
        else
        {
            cout << "Customers currently waiting:" << endl;
            int i = front;
            while (true)
            {
                cout << "Name: " << arr[i].name << " | Transaction: " << arr[i].transaction << endl;
                if (i == back)
                {
                    break;
                }
                i = (i + 1) % size;
            }
        }
    }

    void totalCustomers()
    {
        cout << "Total customers waiting: " << count << endl;
    }
};

int main()
{
    int choice;
    char again;
    int size;

    cout << "Enter maximum number of customers queue can hold: ";
    cin >> size;

    Queue q(size);

    do
    {
        cout << endl;
        cout << "1. Add a Customer (Enqueue)" << endl;
        cout << "2. Serve a Customer (Dequeue)" << endl;
        cout << "3. Display All Waiting Customers" << endl;
        cout << "4. Show Total Number of Waiting Customers" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Customer c;
            cout << "Enter Customer Name: ";
            cin >> c.name;
            cout << "Enter Transaction Type (Deposit / Withdrawal / Loan Inquiry): ";
            cin >> c.transaction;
            q.enqueue(c);
        }
        else if (choice == 2)
        {
            q.dequeue();
        }
        else if (choice == 3)
        {
            q.display();
        }
        else if (choice == 4)
        {
            q.totalCustomers();
        }
        else
        {
            cout << "Invalid choice." << endl;
        }

        cout << endl << "Do you want to continue? (y/n): ";
        cin >> again;

    } while (again == 'y');

    return 0;
}
