#include<iostream>
using namespace std;
struct Queue{
    int *arr;
    int front,rear,size;

    Queue(int s){
        size =s;
        front,rear=-1;
        arr = new int[s];
    }
    bool isEmpty(){
        return rear == -1;

    }
    bool isfull(){
        return front == rear;
    }

    void enqueue(int val){
        if (isEmpty()){
            front=0;
        }
        if (!isfull()){
            arr[++rear]=val;
        }
        
    }
    void dequeue(){
        if (!isEmpty()){
            cout<<arr[front++]<<"Is dequeued"<<endl;

        }
    }
    void top(){
        if (!isEmpty()){
            cout<<arr[front]<<" Front element "<<endl;
        }
    }
    void Display(){
        if (!isEmpty()){
            cout<<arr[front]<<"  IS DISPLAYED"<<endl;
        }
    }
};
int main()
{   Queue q1(5);
    q1.enqueue(12);
    // q1.dequeue();
    q1.enqueue(1);
    q1.enqueue(2);
    q1.top();
    q1.Display();

      return 0;
}