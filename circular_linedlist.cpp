#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = nullptr;
    }

    // Insert at the end
    void insert(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            head->next = head;  // Points to itself
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
    }

    // Insert at the beginning
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            head->next = head;
            return;
        }

        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }

        temp->next = newNode;
        newNode->next = head;
        head = newNode;  // Update head
    }

    // Delete node by value
    void deleteNode(int val) {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* curr = head;
        Node* prev = nullptr;

        // Special case: deleting head
        if (head->data == val) {
            // Only one node
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }

            // Find last node to update its next
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            last->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        // Deleting non-head node
        do {
            prev = curr;
            curr = curr->next;

            if (curr->data == val) {
                prev->next = curr->next;
                delete curr;
                return;
            }
        } while (curr != head);

        cout << "Value " << val << " not found in the list.\n";
    }

    // Display the list
    void display() {
        if (head == nullptr) {
            cout << "List is empty.\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }

    // Search for an element
    bool search(int val) {
        if (head == nullptr) return false;

        Node* temp = head;
        do {
            if (temp->data == val)
                return true;
            temp = temp->next;
        } while (temp != head);

        return false;
    }

    // Destructor to free memory
    ~CircularLinkedList() {
        if (head == nullptr) return;

        Node* curr = head->next;
        while (curr != head) {
            Node* temp = curr;
            curr = curr->next;
            delete temp;
        }
        delete head;
        head = nullptr;
    }
};
