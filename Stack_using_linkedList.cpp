#include <iostream>
using namespace std;
struct Node
{
    /* data */
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
struct Stack_using_linkedList
{
    /* data */
    Node *top;
    Stack_using_linkedList()
    {
        top = nullptr;
    }
    bool isEmpty()
    {
        return top == nullptr;
    }
    void push(int val)
    {
        Node *newnode = new Node(val);
        newnode->next = top;
        top = newnode;
    }
    void pop()
    {
        if (!isEmpty())
        {
            Node *to_del = top;
            top = top->next;
            delete to_del;
        }
    }
    void Display(){
        Node *temp = top;
        if (!temp) return;
        while (temp != nullptr)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
    void peek(){
        if (!top) return;
        else{ cout<<"Element at the top"<<top->data<<endl;}
    }
};

int main()
{
    Stack_using_linkedList st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Stack elements:" << endl;
    st.Display();

    st.pop();
    cout << "After one pop:" << endl;
    st.Display();
    st.peek();

    return 0;
}