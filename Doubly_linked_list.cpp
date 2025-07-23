#include <iostream>
using namespace std;
struct Node
{
public:
    // Node structure for linked list
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

struct Doubly_linked_list
{
    Node *head;
    Doubly_linked_list()
    {
        head = nullptr;
    }
    void Insert_at_the_end(int val)
    {
        Node *newnode = new Node(val);
        if (!head)
        {
            head = newnode;
        }
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = newnode;
            newnode->prev = temp;
        }
    }
    void Display()
    {
        if (!head)
            return;
        else
        {
            Node *temp = head;
            while (temp != nullptr)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void Delete_at_first()
    {
        if (!head)
            return;
        if (!head->next)
            head = nullptr;
        else
        {
            Node *del = head;
            head = head->next;
            delete del;
        }
    }
    void Delete_at_last()
    {
        if (!head)
            return;
        if (!head->next)
            head = nullptr;
        else
        {
            Node *temp = head;
            while (temp->next->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next=nullptr;

        }
    }
    void Delete_at_key(int val, int key) {
        if (!head || key < 0) return;
        Node* temp = head;
        int pos = 0;
        // If deleting the head node
        if (key == 0) {
            Node* del = head;
            head = head->next;
            if (head) head->prev = nullptr;
            delete del;
            return;
        }
        // Traverse to the node just before the one to delete
        while (temp != nullptr && pos < key - 1) {
            temp = temp->next;
            pos++;
        }
        // If position is invalid or next node is null
        if (temp == nullptr || temp->next == nullptr) return;
        Node* del = temp->next;
        temp->next = del->next;
        if (del->next) {
            del->next->prev = temp;
        }
        delete del;
    }
    void insert_at_key(int val,int key){
        Node * newnode= new Node(val);
        if (key==0 && head)
        {
            newnode->next=head;
            head->prev=newnode;
            head = newnode;
        }
        if (!head){
           head=newnode;
        }
        else{
            Node* temp = head;
            int pos = 0;
            while (temp!=nullptr && pos < key-1)
            {
                temp=temp->next;
                pos++;
            }
        }
    }
    void Reverse_Linked_list(){
        if (!head) return;
        Node*current = head;
        Node* prev =nullptr;
        while (current!=nullptr)
        {
            prev =current->prev;
            current->prev=current->next;
            current->next=prev;
            current=current->prev;
        }
        if (current!=nullptr){
            head =current->prev;
        }
        
    }
};

int main()
{
    Doubly_linked_list d;
    d.Insert_at_the_end(2);
    d.Insert_at_the_end(6);
    d.Insert_at_the_end(4);
    d.Insert_at_the_end(1);
    d.Display();
    d.Delete_at_first();
    d.Display();
    d.Delete_at_last();
    d.Display();

    return 0;
}