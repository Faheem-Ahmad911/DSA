#include <iostream>
using namespace std;

struct CircularQueue {
    int front, rear, size;
    int *arr;

    CircularQueue(int s) {
        size = s;
        arr = new int[s];
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1);
    }

    bool isFull() {
        return (front == (rear + 1) % size);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue is Full" << endl;
            return;
        }

        if (isEmpty()) {
            front = 0;
        }

        int pos = (rear + 1) % size;
        rear = pos;
        arr[rear] = val;
        cout << val << " is enqueued at position " << rear << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty, nothing to dequeue" << endl;
            return;
        }

        int val = arr[front];
        cout << val << " is dequeued from position " << front << endl;

        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % size;
        }
    }

    void top() {
        if (isEmpty()) {
            cout << "Queue is Empty, no front element" << endl;
        } else {
            cout << "Front element: " << arr[front] << " at position " << front << endl;
        }
    }

    void back() {
        if (isEmpty()) {
            cout << "Queue is Empty, no rear element" << endl;
        } else {
            cout << "Rear element: " << arr[rear] << " at position " << rear << endl;
        }
    }

    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5); // Queue of size 5

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.top();
    q.back();

    q.dequeue();

    q.top();
    q.back();

    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); // Should say "Queue is Full"

    q.top();
    q.back();

    q.enqueue(70); // Try to enqueue when full

    q.dequeue();
    q.dequeue();

    q.top();
    q.back();

    return 0;
}
