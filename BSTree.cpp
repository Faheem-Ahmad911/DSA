#include<iostream>
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
    Node* insert(Node* root, int key) {
        if (root == nullptr) return new Node(key);
        if (root->data == key) return root;
        if (key < root->data)
            root->left = insert(root->left, key);
        else
            root->right = insert(root->right, key);
        return root;
    }
    Node* getSuccessor(Node* curr){
        curr =curr->right;
        while (curr!=nullptr && curr->left != nullptr)
        {
            /* code */
            curr=curr->left;
        }
        return curr;
    }
    Node* deletion(Node * root,int key){
        if (root == nullptr) return root;
        else if (key<root->data) root->left= deletion(root->left,key);
        else if (key>root->data) root->right=deletion(root->right,key);
        else{
            if (root->left == nullptr){
                Node* temp = root->right;
                delete root;
                return temp;
            }
            if (root->right == nullptr){
                Node* temp = root->left;
                delete root;
                return temp;
            }
            Node* succ = getSuccessor(root);
            root->data=succ->data;
            root->right=deletion(root->right,succ->data);
        }
        return root;
    }
    // Node* searching(Node* root,int key){
    //     if (root== nullptr || root->data== key) return;
    //     if (key<root->data){
    //         return searching(root->left);
    //     }
    //     else{
            
    //     }

    // }
};
int main()
{
      return 0;
}