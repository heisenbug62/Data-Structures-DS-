#include <iostream>
using namespace std;

class employee {
public:
	virtual int calcsalary() = 0;
};

class fulltime : public employee {
protected:
	const int sal;
	int hrs;

public:
	fulltime(int h) : sal(7000), hrs(h) {}

	int calcsalary()
	{
		return sal * hrs;
	}

};

class parttime : public employee {
protected:
	int sal;
	int h;
	
public:
	parttime(int s, int hrs)
	{
		sal = s;
		h = hrs;
		
	}

	int calcsalary() override
	{
		return sal * h ;
	}
};

int main()
{
	parttime A(4600, 7);
	fulltime B(5);

	cout << A.calcsalary() << "is the salary of the PartTime Employee A" << endl;
	cout << B.calcsalary() << "is the salary of the FullTime Employee B";

	return 0;
}
