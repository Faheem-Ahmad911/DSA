#include <iostream>
using namespace std;
struct Stack
{
public:
    int *arr;
    int top;
    int size;
    Stack(int s)
    {
        size = s;
        arr = new int[size];
        top = size;
    }
    bool isEmpty()
    {
        return top == size;
    }
    bool isfull()
    {
        return top == 0;
    }
    void push(int val)
    {
        if (!isfull())
        {
            arr[--top] = val;
        }
        else
        {
            cout << "Stack is Full" << endl;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "Nothing to pop" << endl;
        }
        int val = arr[top++];
        cout << val << " is popped" << endl;
    }
    void Display()
    {
        if (isEmpty())
        {
            cout << "Stack is Empty" << endl;
        }
        else
        {
            for (int i = top; i < size; i++)
            {
                cout << arr[i] << endl;
            }
        }
    }
};

int main()
{   Stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.pop();
    s.Display();
    return 0;
}