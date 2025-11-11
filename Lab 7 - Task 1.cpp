#include "node.h"
class LL {
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

		if (head==nullptr && tail==nullptr)
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
		if (head == nullptr && tail == nullptr)
		{
			cout << "LL is Empty";
			return;
		}

		else
		{
			node* t = head;
			while (1)
			{
				cout << t->data << " ";
				t = t->next;

				if (t == nullptr)
				{
					break;
				}
			}
		}
	}

	int count()
	{
		node* t=head;
		int counter = 0;
		while (t!=nullptr)
		{
			t = t->next;
			counter++;
		}

		return counter;
	}
};

int main()
{
	LL obj;

	obj.InsertAtEnd(12);
	obj.InsertAtEnd(14);
	obj.InsertAtEnd(17);
	obj.InsertAtEnd(19);

	obj. display();
	cout << endl;
	int num = obj.count();
	cout << "LL has " << num << " nodes";
}