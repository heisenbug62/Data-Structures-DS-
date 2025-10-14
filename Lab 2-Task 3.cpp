#include <iostream>
#include <cstring>
using namespace std;

class LibraryItem {
public:
    virtual void display() const = 0;
    virtual const char* getKey() const = 0;
    virtual ~LibraryItem() {}
};

class Book : public LibraryItem {
private:
    char title[50];
    char author[50];
    int pages;
public:
    Book(const char* t = "", const char* a = "", int p = 0) {
        strcpy(title, t);
        strcpy(author, a);
        pages = p;
    }
    const char* getTitle() const { return title; }
    int getPages() const { return pages; }
    void display() const override {
        cout << "Book Title: " << title << ", Author: " << author << ", Pages: " << pages << endl;
    }
    const char* getKey() const override { return title; }
};

class Newspaper : public LibraryItem {
private:
    char name[50];
    char date[20];
    char edition[50];
public:
    Newspaper(const char* n = "", const char* d = "", const char* e = "") {
        strcpy(name, n);
        strcpy(date, d);
        strcpy(edition, e);
    }
    const char* getName() const { return name; }
    const char* getEdition() const { return edition; }
    void display() const override {
        cout << "Newspaper Name: " << name << ", Date: " << date << ", Edition: " << edition << endl;
    }
    const char* getKey() const override { return name; }
};

class Library {
private:
    Book books[10];
    Newspaper newspapers[10];
    int bookCount;
    int newspaperCount;
public:
    Library() { bookCount = 0; newspaperCount = 0; }
    void addBook(const Book& b) {
        if (bookCount < 10) books[bookCount++] = b;
    }
    void addNewspaper(const Newspaper& n) {
        if (newspaperCount < 10) newspapers[newspaperCount++] = n;
    }
    void displayCollection() const {
        cout << "\nBooks:\n";
        for (int i = 0; i < bookCount; i++) books[i].display();
        cout << "\nNewspapers:\n";
        for (int i = 0; i < newspaperCount; i++) newspapers[i].display();
    }
    void sortBooksByPages() {
        for (int i = 0; i < bookCount - 1; i++)
            for (int j = i + 1; j < bookCount; j++)
                if (books[i].getPages() > books[j].getPages()) {
                    Book temp = books[i];
                    books[i] = books[j];
                    books[j] = temp;
                }
    }
    void sortNewspapersByEdition() {
        for (int i = 0; i < newspaperCount - 1; i++)
            for (int j = i + 1; j < newspaperCount; j++)
                if (strcmp(newspapers[i].getEdition(), newspapers[j].getEdition()) > 0) {
                    Newspaper temp = newspapers[i];
                    newspapers[i] = newspapers[j];
                    newspapers[j] = temp;
                }
    }
    Book* searchBookByTitle(const char* title) {
        for (int i = 0; i < bookCount; i++)
            if (strcmp(books[i].getKey(), title) == 0) return &books[i];
        return NULL;
    }
    Newspaper* searchNewspaperByName(const char* name) {
        for (int i = 0; i < newspaperCount; i++)
            if (strcmp(newspapers[i].getKey(), name) == 0) return &newspapers[i];
        return NULL;
    }
};
