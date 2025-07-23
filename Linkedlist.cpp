#include <iostream>
using namespace std;
struct Node
{
public:
    // Node structure for linked list
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = nullptr;
    }
};

struct LinkedList
{
    Node *head;
    LinkedList()
    {
        head = nullptr;
    }
    void insert(int val)
    {
        if (!head)
            head = new Node(val);
        else
        {
            Node *temp = head;
            while (temp->next != nullptr)
            {
                temp = temp->next;
            }
            temp->next = new Node(val);
        }
    }
    void Display()
    {
        if (!head)
            cout << "Nothing in Linkedlist to display" << endl;
        else
        {
            Node *temp = head;
            while (temp)
            {
                cout << temp->data << "->";
                temp = temp->next;
            }
            cout << endl;
        }
    }
    void Delete_at_last()
    {
        if (!head)
            cout << "Nothing to delete " << endl;
        else if (!head->next)
        {
            delete head;
            head = nullptr;
        }
        else
        {
            Node *temp = head;
            while (temp->next->next != nullptr)
            {
                /* code */
                temp = temp->next;
            }
            Node *to_del = temp->next;
            temp->next = nullptr;
            delete to_del;
        }
    }
    void Delete_at_first()
    {
        if (!head)
            cout << "Nothing to delete at first" << endl;
        if (!head->next)
            head = nullptr;
        else
        {
            Node *temp = head->next;
            delete head;
            head = temp;
        }
    }
    void Reverse()
    {
        if (!head)
            cout << "Nothing to Reverse" << endl;
        else
        {
            Node *current = head;
            Node *prev = nullptr;
            while (current != nullptr)
            {
                Node *temp = current->next;
                current->next = prev;
                prev = current;
                current = temp;
            }
            head = prev;
        }
    }

    void Insert_after_index(int val, int index)
    {
        if (!head || index < 0)
            cout << "Nothing to insert empty or key is wrong" << endl;
        else
        {
            Node *temp = head;
            int pos = 0;
            Node *newnode = new Node(val);
            while (temp->next != nullptr && pos < index)
            {
                temp = temp->next;
                pos++;
            }
            if (temp->next)
            {
                newnode->next = temp->next;
                temp->next = newnode;
            }
            else
            {
                temp->next = newnode;
                newnode->next = nullptr;
            }
        }
    }
    Node *Middle_element()
    {
        Node *slow = head;
        Node *fast = head;
        if (!head)
        {
            cout << "Nothing to find Middle" << endl;
            return nullptr;
        }
        else
        {
            while (fast != nullptr && fast->next != nullptr)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
        }
        return slow;
    }
    void Search_element(int element)
    {
        if (!head)
            cout << "No element exist" << endl;
        else
        {
            Node *temp = head;
            bool found = false;
            while (temp)
            {
                if (temp->data == element)
                {
                    cout << "Element Found" << endl;
                    found = true;
                    return;
                }
                else
                {
                    temp = temp->next;
                }
            }
            if (!found)
            {
                cout << "NO element found" << endl;
            }
        }
    }
    void Remove_Duplicate(){
        if (!head) cout<<"No Element exist so No Duplicate "<<endl;
        else{
            Node* current = head;
            while(current){
                Node* prev = current;
                Node* mover = current->next;
                while(mover){
                    if(current->data == mover->data){
                        prev->next = mover->next;
                        delete mover;
                        mover = prev->next;
                    }
                    else{
                        prev = mover;
                        mover = mover->next;
                    }
                }
                current = current->next;
            }
        }
    }
};

int main()
{
    LinkedList l1;
    l1.insert(12);
    l1.insert(1);
    l1.insert(2);
    l1.insert(2);
    l1.insert(1);
    l1.insert(1);
    l1.insert(1);

    l1.Display();
    // l1.Delete_at_last();
    // l1.Display();
    // l1.Delete_at_first();
    // l1.Display();
    // l1.Reverse();
    // l1.Display();
    // l1.Insert_after_index(555, -1);
    // l1.Display();
    Node *middle = l1.Middle_element();
    l1.Search_element(299999);
    l1.Remove_Duplicate();
    l1.Display();

    return 0;
}