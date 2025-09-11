/*
Question #77
Source: CPP GeeksforGeeks

Question:
Write a C++ program to implement a stack using a fixed-size array.
Implement push, pop, peek, and isEmpty operations.

My Answer:
✅ Output for operations in main:
- Popped element: 5
- Top element: 4

Reason:
- Use a fixed-size array of size MAX.
- Track top index of the stack.
- Push: Increment top and store element; check for overflow.
- Pop: Return element at top and decrement top; check for underflow.
- Peek: Return element at top.
- isEmpty: Check if top == -1.

If Wrong:
- Ensure top is updated correctly after push/pop.
- Handle underflow/overflow properly.
*/

#include <iostream>
using namespace std;

#define MAX 100

class Stack {
private:
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    void push(int x) {
        if (top == MAX - 1) {
            cout << "Stack overflow" << endl;
            return;
        }
        arr[++top] = x;
    }

    int pop() {
        if (top == -1) {
            cout << "Stack underflow" << endl;
            return -1;
        }
        return arr[top--];
    }

    bool isEmpty() { return (top == -1); }

    int peek() {
        if (top == -1) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }
};

int main() {
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);

    cout << "Popped element: " << s.pop() << endl;
    cout << "Top element: " << s.peek() << endl;

    return 0;
}
