#include <iostream>
using namespace std;
struct CircularQueue
{
    int front, rear, size;
    int *arr;

    CircularQueue(int s)
    {
        size = s;
        arr = new int[s];
        front = -1;
        rear = -1;
    }
    bool isEmpty()
    {
        return front == -1;
    }
    bool isFull()
    {
        return front == (rear + 1) % size;
    }
    void Enqueue(int val)
    {
        if (isFull())
        {
            cout << "Queue is full" << endl;
            return;
        }
        if (isEmpty())
        {
            front = 0;
            rear = 0;
        }
        else
        {
            rear = (rear + 1) % size;
        }
        arr[rear] = val;
    }
    void Dequeue(){
        if (isEmpty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        // Optionally print the dequeued value
        // cout << arr[front] << endl;
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % size;
    }
    // void Display(){
    //     if(!isEmpty()){
    //         for (int i = front;i<rear;i++){

    //             cout<<arr[front]<<endl;
    //         }
    //     }
    // }
    
};
int main()
{   CircularQueue q1(12);
    q1.Enqueue(12);
    q1.Enqueue(13);
    q1.Dequeue();
    // q1.Display();
    return 0;
}