#include <iostream>
using namespace std;

// Node structure
class Node {
public:
    int data;
    Node* next;
    
    Node(int value) {
        data = value;
        next = nullptr;
    }
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    // Enqueue operation (insert at rear)
    void enqueue(int value) {
        Node* newNode = new Node(value);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << value << " enqueued to queue\n";
    }

    // Dequeue operation (remove from front)
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow! Nothing to dequeue.\n";
            return;
        }
        Node* temp = front;
        cout << temp->data << " dequeued from queue\n";
        front = front->next;

        // If queue becomes empty after dequeue
        if (front == nullptr)
            rear = nullptr;

        delete temp;
    }

    // Peek at front element
    int peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Display all elements
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        cout << "Queue elements (Front to Rear): ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

// Driver code
int main() {
    Queue q;

    q.enqueue(100);
    q.enqueue(200);
    q.enqueue(300);
    q.display();

    cout << "Front element is: " << q.peek() << "\n";

    q.dequeue();
    q.display();

    return 0;
}
