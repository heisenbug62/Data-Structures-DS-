#include "node.h"
class LL 
{
protected:
    node* head;
    node* tail;

public:
    LL()
    {
        head = nullptr;
        tail = nullptr;
    }

    void InsertAtEnd(int val)
    {
        node* nn = new node;
        nn->data = val;
        nn->next = nullptr;

        if (head == nullptr && tail == nullptr)
        {
            head = nn;
            tail = nn;
        }
        else
        { 
            tail->next = nn;
            tail = nn;
        }
    }

    void display()
    {
        if (head == nullptr)
        {
            cout << "LL is Empty";
            return;
        }

        node* t = head;
        while (t != nullptr)
        {
            cout << t->data << " ";
            t = t->next;
        }
    }

    void insertinbetween(int val, int after)
    {
        node* nn = new node;
        nn->data = val;
        nn->next = nullptr;

        if (head == nullptr)
        {
            cout << "LL is Empty, can't insert after " << after << endl;
            delete nn;
            return;
        }

		else
		{
        node* t = head;
        while (t != nullptr && t->data != after)
        {
            t = t->next;
        }

        if (t == nullptr)
        {
            cout << "Value " << after << " not found in the list." << endl;
            delete nn;
            return;
        }

        nn->next = t->next;
        t->next = nn;

        if (t == tail)
        {
            tail = nn;
        }
	}
    }
};

int main()
{
    LL obj;

    obj.InsertAtEnd(12);
    obj.InsertAtEnd(14);
    obj.InsertAtEnd(17);
    obj.InsertAtEnd(19);

    obj.insertinbetween(32, 17);
    obj.display();

    return 0;
}
