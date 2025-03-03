#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* left;
    Node* right;

    Node(int value) {
        this->value = value;
        left = right = NULL;
    }
};

Node* create_tree() {
    int n;
    cout << "Enter the value (-1 for no node): ";
    cin >> n;

    if (n == -1) return nullptr;

    Node* newnode = new Node(n);
    cout << "Enter left child of " << n << endl;
    newnode->left = create_tree();
    cout << "Enter right child of " << n << endl;
    newnode->right = create_tree();

    return newnode;
}

void preorder(Node* root) {
    if (root) {
        cout << root->value << " ";
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(Node* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        cout << root->value << " ";
    }
}

void inorder(Node* root) {
    if (root) {
        inorder(root->left);
        cout << root->value << " ";
        inorder(root->right);
    }
}

int main() {
    cout << "Create your binary tree" << endl;
    Node* root = create_tree();

    cout << "\nPre-Order Traversal: ";
    preorder(root);

    cout << "\nIn-Order Traversal: ";
    inorder(root);

    cout << "\nPost-Order Traversal: ";
    postorder(root);

    cout << endl;

    return 0;
}
