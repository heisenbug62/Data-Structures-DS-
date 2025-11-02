#include <iostream>
using namespace std;

struct student {
    string name;
    int timetaken = 0;
    int score = 0.0;

};

class Queue
{
protected:
    student* arr;
    int front, back;
    int size;

public:
    Queue(int s)
    {
        size = s;
        arr = new student[s];
        front = -1;
        back = -1;
    }

    bool isemp()
    {
        return (front == -1 && back == -1);
    }

    bool isfull()
    {
        return (back == size - 1);
    }

    void enqueue(student v)
    {
        if (isfull())
        {
            return;
        }

        else if (isemp())
        {
            front = 0;
            back = 0;
            arr[back] = v;
        }

        else
        {
            back++;
            arr[back] = v;
        }

    }

    void dequeue()
    {
        if (isemp())
        {
            return;
        }

        else if (front == back)
        {
            front = -1;
            back = -1;
        }

        else front++;
    }

    void display()
    {
        if (!isemp())
        {
            for (int i = front; i <= back; i++)
            {
                cout << arr[i].name << " " << arr[i].timetaken << " " << arr[i].score;
            }
        }

    }

};

int main()
{
    student s;
    s.name = "Rohaan";
    s.timetaken=rand();
    s.score = rand();

    Queue q(1);
    q.enqueue(s);

    q.display();
}