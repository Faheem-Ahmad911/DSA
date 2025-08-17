#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

struct Node {
    string word;
    Node* left;
    Node* right;
    Node(string w) {
        word = w;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, string word) {
    if (root == NULL) {
        return new Node(word);
    }
    if (word < root->word) {
        root->left = insert(root->left, word);
    } else if (word > root->word) {
        root->right = insert(root->right, word);
    }
    return root;
}

bool search(Node* root, string word) {
    if (root == NULL) {
        return false;
    }
    if (root->word == word) {
        return true;
    } else if (word < root->word) {
        return search(root->left, word);
    } else {
        return search(root->right, word);
    }
}

string toLowerCase(string word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] >= 'A' && word[i] <= 'Z') {
            word[i] = word[i] + 32;
        }
    }
    return word;
}

string removePunctuation(string word) {
    string result = "";
    for (int i = 0; i < word.length(); i++) {
        if ((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z')) {
            result += word[i];
        }
    }
    return result;
}

void inorder(Node* root) {
    if (root != NULL) {
        inorder(root->left);
        cout << root->word << " ";
        inorder(root->right);
    }
}

void preorder(Node* root) {
    if (root != NULL) {
        cout << root->word << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        cout << root->word << " ";
    }
}

int main() {
    Node* root = NULL;
    ifstream file("dictionary.txt");
    if (!file) {
        cout << "Error opening dictionary file." << endl;
        return 1;
    }

    string word;
    while (getline(file, word)) {
        word = toLowerCase(word);
        word = removePunctuation(word);
        if (!word.empty()) {
            root = insert(root, word);
        }
    }
    file.close();
    cout << "Dictionary loaded." << endl;

    cout << "Enter a sentence: ";
    string sentence;
    getline(cin, sentence);

    stringstream ss(sentence);
    string token;
    cout << "Words found in dictionary: ";
    bool found = false;
    while (ss >> token) {
        token = toLowerCase(token);
        token = removePunctuation(token);
        if (!token.empty() && search(root, token)) {
            cout << token << " ";
            found = true;
        }
    }
    if (!found) {
        cout << "None";
    }
    cout << endl;

    cout << "\nInorder Traversal: ";
    inorder(root);
    cout << "\nPreorder Traversal: ";
    preorder(root);
    cout << "\nPostorder Traversal: ";
    postorder(root);
    cout << endl;

    return 0;
}
