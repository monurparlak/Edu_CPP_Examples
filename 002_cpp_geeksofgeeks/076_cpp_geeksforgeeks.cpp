/*
Question #76
Source: CPP GeeksforGeeks

Question:
Write a C++ program to iterate through an STL queue
without modifying the original queue by creating a copy.

My Answer:
✅ Output:
Queue elements :
1 2 3 4 5

Reason:
- STL queue does not provide iterators.
- To iterate without modifying original queue:
  1. Create a copy of the queue.
  2. Pop elements from the copy and print.
- The original queue remains intact.

If Wrong:
- Avoid using iterators directly; STL queue does not support them.
- Ensure copy_queue is used, not the original queue.
*/

#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;

    // Insert elements
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    // Copy the queue
    queue<int> copy_queue = q;

    cout << "Queue elements :\n";

    while (!copy_queue.empty()) {
        cout << copy_queue.front() << " ";
        copy_queue.pop();
    }

    return 0;
}
