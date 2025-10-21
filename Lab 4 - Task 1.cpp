#include <iostream>
using namespace std;

template <class T>
class Array {
protected:
	int top = -1;
	T* arr;
	int size;

public:
	Array(int capacity)
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

	void peek()
	{
		cout << "Top most book is: " << arr[top] << endl;
	}
};

int main()
{
	Array<string> obj(5);
	obj.push("Theory of time");
	obj.push("Silent Patient");
	obj.push("Rule of wolves");
	obj.push("Man searching for meaning");
	obj.push("Psychology of Money");

	obj.peek();

	obj.pop();
	obj.pop();

	obj.peek();
}