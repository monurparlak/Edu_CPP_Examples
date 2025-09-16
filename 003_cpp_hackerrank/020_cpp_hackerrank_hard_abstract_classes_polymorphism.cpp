/* ================================================================================
HackerRank C++ Challenge: Implementing an LRU Cache with Inheritance
================================================================================

Objective:
----------
- Implement an LRU (Least Recently Used) Cache using C++ class inheritance.
- Extend the abstract base class Cache and implement set() and get() methods.
- Use a doubly linked list for ordering elements from most to least recently used.
- Use a map to store key -> node pointers for O(1) access.

Concepts Covered:
-----------------
- Abstract base classes
- Pure virtual functions
- Doubly linked lists
- Hash map (std::map) for O(1) lookups
- LRU cache policy
- Dynamic memory management

--------------------------------------------------------------------------------
Problem Description:
--------------------------------------------------------------------------------
- Cache has a fixed capacity.
- set(key, value):
    * If key exists, update its value and move it to the head (most recently used).
    * If key does not exist, insert at head.
    * If capacity exceeded, remove tail (least recently used).
- get(key):
    * If key exists, move it to head and return its value.
    * If key does not exist, return -1.

--------------------------------------------------------------------------------
Input Format:
--------------------------------------------------------------------------------
- First line: n (number of commands) and capacity of the cache
- Next n lines: either
    * "get key"
    * "set key value"

--------------------------------------------------------------------------------
Output Format:
--------------------------------------------------------------------------------
- For each "get" command, output the value or -1 if key not found.

Sample Input:
3 1
set 1 2
get 1
get 2

Sample Output:
2
-1
================================================================================
*/

#include <iostream>
#include <map>
using namespace std;

// Node structure for doubly linked list
struct Node {
    Node* next;
    Node* prev;
    int key;
    int value;
    Node(Node* p, Node* n, int k, int val) : prev(p), next(n), key(k), value(val) {}
    Node(int k, int val) : prev(NULL), next(NULL), key(k), value(val) {}
};

// Abstract base class Cache
class Cache {
protected:
    map<int, Node*> mp; // key -> node pointer
    int cp;             // capacity
    Node* head;         // most recently used
    Node* tail;         // least recently used
    virtual void set(int key, int value) = 0;
    virtual int get(int key) = 0;
};

// Derived class LRUCache implementing Cache
class LRUCache : public Cache {
public:
    // Constructor sets capacity and initializes head/tail
    LRUCache(int capacity) {
        cp = capacity;
        head = nullptr;
        tail = nullptr;
    }

    // Get the value of a key
    int get(int key) override {
        if (mp.find(key) == mp.end())
            return -1; // Cache miss

        Node* node = mp[key];
        moveToHead(node); // Move accessed node to head (most recently used)
        return node->value;
    }

    // Set or insert a key-value pair
    void set(int key, int value) override {
        if (mp.find(key) != mp.end()) {
            // Key exists, update value and move to head
            Node* node = mp[key];
            node->value = value;
            moveToHead(node);
        } else {
            // Key does not exist, create new node
            Node* newNode = new Node(key, value);
            mp[key] = newNode;
            addToHead(newNode);

            // Check capacity
            if ((int)mp.size() > cp) {
                // Remove least recently used node (tail)
                mp.erase(tail->key);
                removeTail();
            }
        }
    }

private:
    // Helper: move a node to head
    void moveToHead(Node* node) {
        if (node == head) return; // Already at head

        // Disconnect node
        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;

        // Update tail if needed
        if (node == tail) tail = node->prev;

        // Insert at head
        node->prev = nullptr;
        node->next = head;
        if (head) head->prev = node;
        head = node;
    }

    // Helper: add new node at head
    void addToHead(Node* node) {
        node->prev = nullptr;
        node->next = head;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = node; // First node
    }

    // Helper: remove tail node (least recently used)
    void removeTail() {
        if (!tail) return;
        Node* prevTail = tail;
        if (tail->prev) {
            tail = tail->prev;
            tail->next = nullptr;
        } else {
            // Only one node
            head = tail = nullptr;
        }
        delete prevTail;
    }
};

// --------------------------
// Main function
// --------------------------
int main() {
    int n, capacity;
    cin >> n >> capacity;
    LRUCache l(capacity);

    for (int i = 0; i < n; i++) {
        string command;
        cin >> command;
        if (command == "get") {
            int key;
            cin >> key;
            cout << l.get(key) << endl;
        } else if (command == "set") {
            int key, value;
            cin >> key >> value;
            l.set(key, value);
        }
    }
    return 0;
}

