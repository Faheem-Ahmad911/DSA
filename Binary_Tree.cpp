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

    // Tree Operations inside struct
    Node* insert(Node *root, int val) {
        if (root == nullptr)
            return new Node(val);
        if (val < root->data)
            root->left = insert(root->left, val);
        else
            root->right = insert(root->right, val);
        return root;
    }

    bool search(Node *root, int key) {
        if (root == nullptr)
            return false;
        if (root->data == key)
            return true;
        else if (key < root->data)
            return search(root->left, key);
        else
            return search(root->right, key);
    }

    void inorder(Node* root) {
        if (root != nullptr) {
            inorder(root->left);
            cout << root->data << " ";
            inorder(root->right);
        }
    }

    void preorder(Node *root) {
        if (root != nullptr) {
            cout << root->data << " ";
            preorder(root->left);
            preorder(root->right);
        }
    }

    void postorder(Node *root) {
        if (root != nullptr) {
            postorder(root->left);
            postorder(root->right);
            cout << root->data << " ";
        }
    }
};

int main() {
    Node* tree = nullptr;   // Creating an empty tree
    Node nodeObj(0);        // Dummy object to call methods

    // Insert values into BST
    tree = nodeObj.insert(tree, 15);
    nodeObj.insert(tree, 6);
    nodeObj.insert(tree, 18);
    nodeObj.insert(tree, 3);
    nodeObj.insert(tree, 7);
    nodeObj.insert(tree, 17);
    nodeObj.insert(tree, 2);
    nodeObj.insert(tree, 4);
    nodeObj.insert(tree, 13);

    cout << "Inorder Traversal: ";
    nodeObj.inorder(tree);
    cout << "\n";

    cout << "Preorder Traversal: ";
    nodeObj.preorder(tree);
    cout << "\n";

    cout << "Postorder Traversal: ";
    nodeObj.postorder(tree);
    cout << "\n";

    // Search for a key
    int key = 13;
    if (nodeObj.search(tree, key)) {
        cout << "Key " << key << " found in the BST." << endl;
    } else {
        cout << "Key " << key << " NOT found in the BST." << endl;
    }

    return 0;
}
