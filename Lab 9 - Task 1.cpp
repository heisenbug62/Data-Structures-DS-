#include <iostream>
using namespace std;

struct node
{
	node* prev;
	float duration;
	string name;
	int songID;
	node* next;
};

class songSys
{
protected:
	node* head;
	node* tail;

public:
	songSys()
	{
		head = nullptr;
		tail = nullptr;
	}
	void SongAtEnd(float dur, int id, string n)
	{
		node* nn = new node;
		nn->duration = dur;
		nn->songID = id;
		nn->name = n;
		nn->next = nullptr;
		nn->prev = nullptr;

		if (head == nullptr && tail == nullptr)
		{
			head = nn;
			tail = nn;
		}

		else
		{
			tail->next = nn;
			nn->prev = tail;
			tail = nn;
		}
	}

	bool deleteSong(string song)
	{
		if (head == nullptr && tail == nullptr)
		{
			return 0;
		}

		else if (head->name==song)
		{
			head = head->next;
			delete head->prev;
			head->prev = nullptr;
			return 1;
		}

		else if (tail->name == song)
		{
			tail = tail->prev;
			delete tail->next;
			tail->next = nullptr;
			return 1;
		}

		else
		{
			node* t;

			while (1)
			{
				if (t -> next == nullptr)
				{
					break;
				}

				if (t->name == song)
				{
					node* t2;
					t2 = t -> next;
					t2->prev = t->prev;
					t->prev->next = t2;
					delete t;
					t = nullptr;
					return 1;
				}
				t = t->next;

				if (t == nullptr)
				{
					return false;
				}
			}
		}


	}

	void PlayNext()
	{
		node* current=nullptr;
		if (current == nullptr)
		{
			current = head;

			if (current == nullptr)
			{
				cout << "Playlist is empty."<<endl;
				return;
			}

			cout << "Now Playing: " << current->name << endl;
			return;
		}

		if (current->next == nullptr)
		{
			cout << "You are already at the last song."<<endl;
			return;
		}

		current = current->next;

		cout << "Now Playing: " << current->name
			<< " (ID: " << current->songID
			<< ", Duration: " << current->duration << ")"<<endl;
	}

	void PlayPrevious()
	{
		node* current;
		if (current == nullptr)
		{
			cout << "No current song selected."<<endl;
			return;
		}

		if (current->prev == nullptr)
		{
			cout << "You are already at the first song."<<endl;
			return;
		}

		current = current->prev;

		cout << "Now Playing: " << current->name
			<< " (ID: " << current->songID
			<< ", Duration: " << current->duration << ")"<<endl;
	}

	void DisplayPlaylist()
	{
		if (head == nullptr)
		{
			cout << "Playlist is empty.\n";
			return;
		}

		cout << "---- Playlist ----\n";

		node* temp = head;
		while (1)
		if (temp != nullptr)
		{
			break;
		}

		{
			cout << "ID: " << temp->songID << " | "
				<< "Name: " << temp->name << " | "
				<< "Duration: " << temp->duration << " mins\n";
			temp = temp->next;
		}

		cout << "------------------" << endl;
	}

	void shufflePlaylist()
	{
		if (head == nullptr && tail == nullptr)
		{
			return;
		}

		if (head == tail)
		{
			cout << "you Only have one Song...." << endl;
		}

		else
		{
            node* current=head;
            node* temp=nullptr;
    while (current != NULL) {
        temp = current->prev;         
        current->prev = current->next; 
        current->next = temp;         
        current = current->prev;      
    }

    if (temp != NULL) {
        head = temp->prev;
    }
}

    }

};