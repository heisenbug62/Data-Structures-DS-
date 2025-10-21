#include <iostream>
using namespace std;

template <class T>
class fileName {
protected:
	int top = -1;
	T* arr;
	int size;

public:
	fileName(int capacity)
	{
		size = capacity;
		arr = new T[capacity];
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
			cout << "No Book can be pushed" << endl;
		}

		else
		{
			top++;
			arr[top] = val;
		}
	}

	void pop()
	{
		if (isempty())
		{
			cout << "Already Empty" << endl;
		}

		else
		{
			top--;
			cout << "Book removed" << endl;
		}
	}

	void disp()
	{
		cout << "Recent Folder is: " << arr[top] << endl;
	}
};

int main()
{
	string choice;
	fileName<string> obj(5);
	do
	{
		cout << "Enter Your Choice: " << endl;
		cin >> choice;

		if (choice == "folder")
		{
			obj.push("Folder");
		}

		else if (choice == "cd")
		{
			obj.pop();
		}

		else if (choice == "pwd")
		{
			obj.disp();
		}
	}
	while (choice != "exit");

	return 0;

}