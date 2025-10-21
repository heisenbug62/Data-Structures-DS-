#include <iostream>
using namespace std;

template<typename T>
class Stack {
private:
    int top;
    int capacity;
    T* arr;

public:
    Stack(int size) {
        capacity = size;
        arr = new T[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T value) {
        if (isFull()) {
            cout << "Stack Overflow\n";
            return;
        }
        arr[++top] = value;
    }

    T pop() {
        if (isEmpty()) {
            cout << "Stack Underflow\n";
            return T();
        }
        return arr[top--];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == capacity - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "(empty)";
        }
        else {
            for (int i = top; i >= 0; i--) {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
};

class TextEditor {
private:
    char* text;
    int length;
    int capacity;

    Stack<char> undoStack;
    Stack<char> redoStack;

public:
    TextEditor(int cap) : capacity(cap), undoStack(cap), redoStack(cap) {
        text = new char[capacity];
        length = 0;
    }

    ~TextEditor() {
        delete[] text;
    }

    // User-defined function to append char
    void appendChar(char ch) {
        if (length == capacity) {
            cout << "Text capacity full!" << endl;
            return;
        }
        text[length++] = ch;
    }

    // User-defined function to remove last char
    void removeLastChar() {
        if (length == 0) {
            cout << "No characters to remove!" << endl;
            return;
        }
        length--;
    }

    // Returns current text as a string for printing
    string getText() {
        return string(text, length);
    }

    void type(char ch) {
        appendChar(ch);
        undoStack.push(ch);

        while (!redoStack.isEmpty()) {
            redoStack.pop();
        }
        cout << "Typed '" << ch << "': " << getText() << endl;
    }

    void undo() {
        if (undoStack.isEmpty()) {
            cout << "Nothing to undo." << endl;
            return;
        }
        char lastAction = undoStack.pop();
        removeLastChar();
        redoStack.push(lastAction);

        cout << "Undo: " << getText() << endl;
    }

    void redo() {
        if (redoStack.isEmpty()) {
            cout << "Nothing to redo." << endl;
            return;
        }
        char lastUndone = redoStack.pop();
        appendChar(lastUndone);
        undoStack.push(lastUndone);

        cout << "Redo: " << getText() << endl;
    }

    void displayStacks() {
        cout << "Undo Stack: ";
        undoStack.display();

        cout << "Redo Stack: ";
        redoStack.display();

        cout << endl;
    }

    void displayText() {
        cout << "Current text: " << getText() << endl;
    }
};

int main() {
    TextEditor editor(100);

    editor.type('A');
    editor.type('B');
    editor.type('C');
    editor.displayStacks();

    editor.undo();
    editor.displayStacks();

    editor.undo();
    editor.displayStacks();

    editor.redo();
    editor.displayStacks();

    editor.type('D');
    editor.displayStacks();

    editor.displayText();

    return 0;
}