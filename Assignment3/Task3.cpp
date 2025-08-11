#include <iostream>
using namespace std;
struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
Node *insert(Node *root, int val)
{
    if (root == nullptr)
        return new Node(val);
    if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}
bool Search(Node *root, int val)
{
    if (!root)
        return false;
    if (root->data == val)
        return true;
    else if (val < root->data)
    {
        return Search(root->left, val);
    }
    else
    {
        return Search(root->right, val);
    }

}
Node* findMin(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* remove(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = remove(root->left, key);
    }
    else if (key > root->data) {
        root->right = remove(root->right, key);
    }
    else {
        if (root->left == nullptr && root->right == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }
        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = remove(root->right, temp->data);
        }
    }
    return root;
}

int main()
{
    Node* root = nullptr;
    // Insert some values
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    // Search for a value
    int searchVal = 40;
    if (Search(root, searchVal))
        cout << searchVal << " found in BST.\n";
    else
        cout << searchVal << " not found in BST.\n";

    // Remove a value
    int removeVal = 30;
    root = remove(root, removeVal);
    if (!Search(root, removeVal))
        cout << removeVal << " successfully removed from BST.\n";
    else
        cout << removeVal << " still present in BST.\n";

    return 0;
}