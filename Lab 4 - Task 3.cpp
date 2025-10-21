#include <iostream>
using namespace std;

template <class T>
class callstack {
protected:
	int top = -1;
	T* arr;
	int size;

public:
	callstack(int capacity)
	{
		size = capacity;
		arr = new T[capacity];
	}

	~callstack() {
		delete[] arr;
	}

	bool isempty()
	{
		return top == -1;
	}

	bool isfull()
	{
		return top == size - 1;
	}

	void push(T val)
	{
		if (isfull())
		{
			cout << "No Call can be pushed: Stack is full." << endl;
		}
		else
		{
			arr[++top] = val;
			cout << "New call added: " << val << endl;
		}
	}

	void pop()
	{
		if (isempty())
		{
			cout << "No call to remove: Stack is already empty." << endl;
		}
		else
		{
			cout << "Call removed: " << arr[top--] << endl;
		}
	}

	void peek()
	{
		if (isempty()) {
			cout << "No current call." << endl;
		}
		else {
			cout << "Top most Call is: " << arr[top] << endl;
		}
	}

	void display()
	{
		if (isempty())
		{
			cout << "No calls in the stack." << endl;
		}
		else
		{
			cout << "Current Call Stack (top to bottom):" << endl;
			for (int i = top; i >= 0; i--)
			{
				cout << i + 1 << ". " << arr[i] << endl;
			}
		}
	}
};

int main()
{
	int size;
	cout << "Enter max number of concurrent calls: ";
	cin >> size;

	callstack<string> callStack(size);
	int choice;
	string call;

	do {
		cout << "\n--- Mobile Call Stack Menu ---\n";
		cout << "1. Push (New Call)\n";
		cout << "2. Pop (End Call)\n";
		cout << "3. Peek (Check Current Call)\n";
		cout << "4. isEmpty (Check if stack is empty)\n";
		cout << "5. Display All Calls\n";
		cout << "0. Exit\n";
		cout << "Enter your choice: ";
		cin >> choice;

		cin.get();

		switch (choice) {
		case 1:
			cout << "Enter call info (e.g., name or number): ";
			getline(cin, call);
			callStack.push(call);
			break;
		case 2:
			callStack.pop();
			break;
		case 3:
			callStack.peek();
			break;
		case 4:
			if (callStack.isempty())
				cout << "Call stack is empty." << endl;
			else
				cout << "There are ongoing calls." << endl;
			break;
		case 5:
			callStack.display();
			break;
		case 0:
			cout << "Exiting program. Goodbye!" << endl;
			break;
		default:
			cout << "Invalid choice. Please try again." << endl;
		}
	} while (choice != 0);

	return 0;
}
