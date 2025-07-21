#include <iostream>
using namespace std;
struct Queue
{
public:
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
        {
            if (front == -1)
                front = 0; // Initialize front if it's the first element
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
                if (front == rear)
                {
                    front = rear = -1;
                }
                else
                {
                    front++;
                }
            }
        }
    }
    void top()
    {
        if (!isEmpty())
        {
            int f = arr[front];
            cout << "Top element: " << f << endl;
        }
        else
        {
            cout << "Front is Empty" << endl;
        }
    }
    void Display()
    {
        if (!isEmpty())
        {
            for (int i = front; i <= rear; i++)
            {
                cout << arr[i] << " " << endl;
            }
        }
        else
        {
            cout << "Queue is Empty" << endl;
        }
    }
    void RemoveDuplicate(Queue &q)
    {
        int s = q.rear - q.front + 1;
        int unique_elements[s];
        int ind;
        for (int i = q.front; i < q.rear; i++)
        {
            bool isDup = false;
            for (int j = q.front + 1; j < q.rear; j++)
            {
                if (arr[i] == arr[j])
                {
                    isDup = true;
                    break;
                }
            }
            if (!isDup)
            {
                unique_elements[ind++] = arr[i];
            }
        }
        q.front = 0;
        q.rear = ind - 1;
        for (int i = 0; i < ind; i++)
        {
            q.arr[i] = unique_elements[i]; // Update the queue with unique elements
        }
    }
    int Max_element()
    {
        if (!isEmpty())
        {
            int max = arr[front];
            for (int i = front + 1; i <= rear; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                }
            }
            return max;
        }
        else
        {
            cout << "Queue is Empty" << endl;
            return -1; // or throw an exception if preferred
        }
    }
    int Second_Max() {
        if (isEmpty() || front == rear) {
            cout << "No second maximum exists" << endl;
            return -1;
        }
        int F_max = arr[front];
        int S_max = -1;
        for (int i = front + 1; i <= rear; i++) {
            if (arr[i] > F_max) {
                S_max = F_max;
                F_max = arr[i];
            } else if (arr[i] < F_max && arr[i] > S_max) {
                S_max = arr[i];
            }
        }
        if (S_max == -1) {
            cout << "No second maximum exists" << endl;
            return -1;
        }
        return S_max;
    }
    void Stack_using_queue(int val){
        Queue temp(size);
        temp.enqueue(val);
        while(!isEmpty()){
            temp.enqueue(arr[front]);
            Dequeue();
        }
        while(!temp.isEmpty()){
            enqueue(temp.arr[temp.front]);
            temp.Dequeue();
        }
    }
    ~Queue()
    {
        delete[] arr;
    }
};

int main()
{
    Queue q1(10);
    q1.enqueue(5);
    q1.enqueue(10);
    q1.enqueue(15);
    q1.Dequeue();
    q1.Display();
    q1.top();
    return 0;
}