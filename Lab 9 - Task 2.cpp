#include <iostream>
using namespace std;

struct node 
{
    node* next;
    int score;
    int pID;
};

class playerSys 
{
protected:
    node* tail;

public:
    playerSys() 
    {
        tail = nullptr;
    }

    void insertPlayer(int s, int id) 
    {
        node* nn = new node;
        nn->score = s;
        nn->pID = id;
        nn->next = nullptr;

        if (tail == nullptr) 
        {
            tail = nn;
            tail->next = tail; 
        } 
        else 
        {
            nn->next = tail->next; 
            tail->next = nn;       
            tail = nn;             
        }
    }

    void deletePlayer(int id)
    {
        if(tail==nullptr)
        {
            return;
        }

        else 
        {
            node* t = tail->next;
            while(1)
            {
                if(t->next==tail)
                {
                    break;
                }

                if(t->next->pID==id)
                {
                    t->next=t->next->next;
                    delete t;
                    t=nullptr;
                }
                else{
                    t=t->next;
                }
            }
        }
    }

    void shifter()
    {
        if(tail==nullptr)
        {
            return;
        }

        if(tail->next==tail)
        {
            cout << "Only one player exists." << endl;
            return;
        }

        node* t=tail->next;

        cout << "Now its: " << t->pID << "'s turn." << endl;
        tail=tail->next;
    }

    void skipPlayer()
     {
        node*current=tail->next;
    if (current == NULL || current->next == NULL) return;
    current = current->next->next;
    }
    

};