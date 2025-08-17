#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

Node* insertNode(Node *root, int val) {
    if (root == nullptr)
        return new Node(val);
    if (val < root->data) {
        root->left = insertNode(root->left, val);
    }
    else if (val > root->data) {
        root->right = insertNode(root->right, val);
    }
    return root;
}

bool searchNode(Node *root, int val) {
    if (!root)
        return false;
    if (root->data == val)
        return true;
    else if (val < root->data) {
        return searchNode(root->left, val);
    }
    else {
        return searchNode(root->right, val);
    }
}

Node* findMinNode(Node* root) {
    while (root && root->left != nullptr)
        root = root->left;
    return root;
}

Node* deleteNode(Node* root, int key) {
    if (root == nullptr) return root;

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    }
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
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
            Node* temp = findMinNode(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }
    }
    return root;
}

int main() {
    Node* root = nullptr;
    // Insert some values
    root = insertNode(root, 50);
    root = insertNode(root, 30);
    root = insertNode(root, 70);
    root = insertNode(root, 20);
    root = insertNode(root, 40);
    root = insertNode(root, 60);
    root = insertNode(root, 80);

    // Search for a value
    int searchVal = 40;
    if (searchNode(root, searchVal))
        cout << searchVal << " found in BST.\n";
    else
        cout << searchVal << " not found in BST.\n";

    // Remove a value
    int removeVal = 30;
    root = deleteNode(root, removeVal);
    if (!searchNode(root, removeVal))
        cout << removeVal << " successfully removed from BST.\n";
    else
        cout << removeVal << " still present in BST.\n";

    return 0;
}
