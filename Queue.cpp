#include <iostream>
using namespace std;
struct Queue
{   public:
    int front, rear, size;
    int *arr;
    Queue(int s)
    {
        size = s;
        arr = new int[s];
        front = -1;
        rear = -1;
    }
    bool isFull()
    {
        return (rear == size - 1);
    }
    bool isEmpty()
    {
        return front == -1;
    }
    void enqueue(int val)
    {
        if (!isFull())
        {   if(front == -1) front = 0; // Initialize front if it's the first element
            arr[++rear] = val;
        }
        else
        {
            cout << "Queue is Full" << endl;
        }
    }
    void Dequeue()
    {
        if (isEmpty())
        {
            cout << "Nothing to dequeue" << endl;
        }
        else
        {
            {
                int val = arr[front];
                cout << val << " is removed" << endl;
                if (front == rear){
                    front =rear = -1;
                }
                else
                {
                    front++;
                }
            }
            
        }
    }
    void top(){
        if(!isEmpty()){
            int f=arr[front];
            cout<<"Top element: "<<f<<endl;
        }
        else{
            cout<<"Front is Empty"<<endl;
        }
    }
    void Display(){
        if (!isEmpty()){
            for (int i = front ; i <= rear; i++){
                cout << arr[i] << " " << endl;
            }
        }
        else{
            cout << "Queue is Empty" << endl;
        }
    }
    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{ Queue q1(10);
    q1.enqueue(5);
    q1.enqueue(10);
    q1.enqueue(15);
    q1.Dequeue();
    q1.Display();
    q1.top();
    return 0;
}