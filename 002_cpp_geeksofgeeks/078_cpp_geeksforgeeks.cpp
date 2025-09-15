/*
Question #78
Source: CPP GeeksforGeeks

Question:
Write a C++ program to implement a queue using a fixed-size array.
Implement enqueue, dequeue, peek, and isEmpty operations.

My Answer:
✅ Output for operations in main:
- Dequeued element: 1
- Front element: 2

Reason:
- Use a fixed-size array of size MAX.
- Track front and rear indices.
- Enqueue: Increment rear and insert element; initialize front if -1.
- Dequeue: Remove element at front; reset front and rear if queue becomes empty.
- Peek: Return element at front.
- isEmpty: Check if front == -1.

If Wrong:
- Check for overflow before enqueue.
- Check for underflow before dequeue.
*/

#include <iostream>
using namespace std;

#define MAX 100

class Queue {
private:
    int front, rear;
    int arr[MAX];

public:
    Queue() { front = rear = -1; }

    void enqueue(int x) {
        if (rear == MAX - 1) {
            cout << "Error: Queue overflow" << endl;
            return;
        }
        arr[++rear] = x;
        if (front == -1) front = 0;
    }

    int dequeue() {
        if (front == -1) {
            cout << "Queue underflow" << endl;
            return -1;
        }
        int x = arr[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return x;
    }

    bool isEmpty() { return (front == -1); }

    int peek() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main() {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);

    cout << "Dequeued element: " << q.dequeue() << endl;
    cout << "Front element: " << q.peek() << endl;

    return 0;
}
