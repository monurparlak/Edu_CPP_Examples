/*
Question #80
Source: CPP GeeksforGeeks

Question:
Write a C++ program to implement a stack using the standard library list container.
Implement push, pop, top, size, empty, and a function to print all elements.

My Answer:
✅ Output for operations in main:
- Size after pushes: 4
- Top element: 4
- Top after pop: 3
- Top after another pop: 2
- Size at the end: 2

Reason:
- Use a list to store elements.
- Push: insert at front.
- Pop: remove front element if not empty.
- Top: return front element.
- Size: track using a counter `cs`.
- Empty: check if `cs` is zero.

If Wrong:
- Ensure `cs` is correctly updated on push/pop.
- Check `empty()` before popping to avoid errors.
*/

#include <bits/stdc++.h>
using namespace std;

template <typename T> 
class Stack {
public:
    list<T> l;
    int cs = 0; // current size

    void push(T d) {
        cs++;
        l.push_front(d);
    }

    void pop() {
        if (cs <= 0) {
            cout << "Stack empty" << endl;
        } else {
            cs--;
            l.pop_front();
        }
    }

    bool empty() { return cs == 0; }

    T top() { return l.front(); }

    int size() { return cs; }

    void print() {
        for (auto x : l)
            cout << x << endl;
    }
};

int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Size: " << s.size() << endl;
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element: " << s.top() << endl;
    s.pop();
    cout << "Top element: " << s.top() << endl;
    cout << "Size: " << s.size() << endl;

    return 0;
}
