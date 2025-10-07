#include <iostream>
using namespace std;

class course {
public:
	virtual int duration(int w, int h) = 0;
};


class online : public course {
protected:
	int week;
	int hrs;

public:
	online(int w, int h) : week(w), hrs(h) {}

	int duration(int w, int h)
	{
		return w * h;
	}

};

class offline : public course {
protected:
	int months;
	int hrsd;

public:
	offline(int m, int h) : months(m), hrsd(h) {}

	int duration(int m, int h)
	{
		return m * h;
	}
};

int main()
{
	online A(5, 6);
	offline B(4, 2);

	cout << A.duration(5, 6);
	cout << B.duration(4, 2);
}