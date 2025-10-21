//#include <iostream>
//using namespace std;
//
//template <class T>
//class Array {
//protected:
//    int top = -1;
//    T* arr;
//    int size;
//
//public:
//    Array(int capacity) {
//        size = capacity;
//        arr = new T[capacity];
//    }
//
//    ~Array() {
//        delete[] arr;
//    }
//
//    bool isEmpty() {
//        return top == -1;
//    }
//
//    bool isFull() {
//        return top == size - 1;
//    }
//
//    void push(T val) {
//        if (isFull()) {
//            cout << "Stack overflow, cannot push" << endl;
//        }
//        else {
//            arr[++top] = val;
//        }
//    }
//
//   
//    T pop() {
//        if (isEmpty()) {
//            cout << "Stack underflow, cannot pop" << endl;
//            return T(); 
//        }
//        else {
//            return arr[top--];
//        }
//    }
//
//    T peek() {
//        if (isEmpty()) {
//            cout << "Stack is empty" << endl;
//            return T();
//        }
//        else {
//            return arr[top];
//        }
//    }
//
//   static  string reverseString(const string& str) {
//        Array<char> s(str.length());
//
//        for (int i = 0; i < (int)str.length(); i++) {
//            s.push(str[i]);
//        }
//
//        string reversed = "";
//        while (!s.isEmpty()) {
//            reversed += s.pop();
//        }
//
//        return reversed;
//    }
//};
//
//int main() {
//    string input = "Hello";
//    cout << "Original String: " << input << endl;
//    cout << "Reversed String: " << Array<char>::reverseString(input) << endl;
//    return 0;
//}


