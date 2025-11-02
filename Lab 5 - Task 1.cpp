#include <iostream>
using namespace std;

template <class T>
class Queue
{
protected:
    T* arr;
    int front, back;
    int size;

public:
    Queue(int s)
    {
        size = s;
        arr = new T[s];
        front = -1;
        back = -1;
    }

    ~Queue()
    {
        delete[] arr;
    }

    bool isemp()
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

    bool isfull()
    {
        if (back == size - 1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void enqueue(T val)
    {
        if (isfull())
        {
            cout << "Queue Overflow" << endl;
        }
        else if (isemp())
        {
            front = 0;
            back = 0;
            arr[back] = val;
        }
        else
        {
            back++;
            arr[back] = val;
        }
    }

    void dequeue()
    {
        if (isemp())
        {
            cout << "Queue Underflow" << endl;
        }
        else if (front == back)
        {
            front = -1;
            back = -1;
        }
        else
        {
            front++;
        }
    }

    void display()
    {
        if (isemp())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            for (int i = front; i <= back; i++)
            {
                cout << arr[i] << "  ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Queue<int> q(5);
    int choice;
    char a;

    do
    {
        cout << endl;
        cout << "1. Enter Value" << endl;
        cout << "2. Delete Value" << endl;
        cout << "3. Check isFull" << endl;
        cout << "4. Check isEmpty" << endl;
        cout << "5. Display" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            int val;
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.enqueue(val);
        }
        else if (choice == 2)
        {
            q.dequeue();
        }
        else if (choice == 3)
        {
            if (q.isfull())
            {
                cout << "Queue is Full" << endl;
            }
            else
            {
                cout << "Queue is Not Full" << endl;
            }
        }
        else if (choice == 4)
        {
            if (q.isemp())
            {
                cout << "Queue is Empty" << endl;
            }
            else
            {
                cout << "Queue is Not Empty" << endl;
            }
        }
        else if (choice == 5)
        {
            q.display();
        }
        else
        {
            cout << "Invalid Choice" << endl;
        }

        cout << "Want to run again (y/n): ";
        cin >> a;

    } while (a == 'y');

    return 0;
}
