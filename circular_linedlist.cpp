#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};
struct circular_linedlist
{
    /* data */
    Node *head;
    circular_linedlist()
    {
        head = nullptr;
    }
    void Insert_at_the_end(int v)
    {
        Node *newnode = new Node(v);
        if (!head)
        {
            head = newnode;
            head->next = head;
            head = newnode;
        }
        else{
            Node * temp =head;
            while(temp!=nullptr){
                temp=temp->next;
            }
            temp->next=newnode;
            newnode->next=head;
            head = newnode;
        }
    }
};

int main()
{
    return 0;
}