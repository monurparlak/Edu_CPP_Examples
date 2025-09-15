/*
Question #79
Source: CPP GeeksforGeeks

Question:
Write a C++ program to implement a stack using two queues.
Implement push, pop, top, and size operations.

My Answer:
✅ Output for operations in main:
- Size after pushes: 4
- Top element: 4
- Top after pop: 3
- Top after another pop: 2
- Size at the end: 2

Reason:
- Use two queues q1 and q2.
- Push: Insert new element into empty q2, then move all elements from q1 to q2, then swap q1 and q2.
- Pop: Remove element from front of q1.
- Top: Return front of q1.
- Size: Return q1.size().

If Wrong:
- Ensure proper swapping of q1 and q2 after each push.
- Check for empty queue before pop/top operations.
*/

#include <bits/stdc++.h>
using namespace std;

class Stack {
    queue<int> q1, q2;

public:
    void push(int x) {
        q2.push(x);

        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }

    void pop() {
        if (!q1.empty())
            q1.pop();
    }

    int top() {
        if (q1.empty()) return -1;
        return q1.front();
    }

    int size() {
        return q1.size();
    }
};

int main() {
    Stack s;

    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    cout << "Size: " << s.size() << endl;
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << "Size: " << s.size() << endl;

    return 0;
}
