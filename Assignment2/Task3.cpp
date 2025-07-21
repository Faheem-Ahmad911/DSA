#include <iostream>
using namespace std;
struct Stack
{
    int topIndex;
    int *arr;
    int size;
    Stack(int s)
    {
        size = s;
        arr = new int[size];
        topIndex = -1;
    }
    bool isEmpty()
    {
        return topIndex == -1;
    }
    bool isFull()
    {
        return topIndex == size - 1;
    }
    void push(int val)
    {
        if (!isFull())
        {
            arr[++topIndex] = val;
        }
    }
    void pop()
    {
        if (!isEmpty())
        {
            int val = arr[topIndex--];
            cout<<val << " is popped from stack" << endl;
        }
        else
        {
            cout << "Empty Nothing to POP" << endl;
        }
    }
    int Size()
    {
        return size;
    }
    int topElement()
    {
        if (isEmpty())
        {
            return -1;
        }
        else
        {
            return arr[topIndex];
        }
    }
    void Display(){
        for (int i = topIndex; i >= 0; i--){
            cout << arr[i] << endl;
        }
    }
   
    void Queue_using_stack(int val) {
       
        Stack temp(size);
     
        while (!isEmpty()) {
            temp.push(topElement());
            pop();
        }
      
        push(val);
      
        while (!temp.isEmpty()) {
            push(temp.topElement());
            temp.pop();
        }
    }
};
int main()
{
    Stack s(5);

    
    s.push(10);
    s.push(20);
    s.push(30);

   
    cout << "Stack elements:" << endl;
    s.Display();

  
    s.pop();

   
    cout << "Stack after pop:" << endl;
    s.Display();

    if (s.isEmpty())
        cout << "Stack is empty." << endl;
    else
        cout << "Stack is not empty." << endl;
    if (s.isFull())
        cout << "Stack is full." << endl;
    else
        cout << "Stack is not full." << endl;


    cout << "Enqueue 40 using Queue_using_stack:" << endl;
    s.Queue_using_stack(40);

    cout << "Stack after enqueue (should behave like queue):" << endl;
    s.Display();

    return 0;
}
