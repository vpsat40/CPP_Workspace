#include <iostream>
using namespace std;

// Data structure to store a binary tree node
struct Node
{
    char data;
    Node *left, *right;

    Node(char data)
    {
        this->data = data;
        this->left = this->right = nullptr;
    }
};

Node* root = nullptr;

Node* getNewNode(char data)
{
    Node* newNode = new Node(data);
    return newNode;
}

Node* insertNode(Node* root, char data)
{
    if(root == nullptr)
        root = getNewNode(data);
    else if(data <= root->data)
        root->left = insertNode(root->left, data);
    else
        root->right = insertNode(root->right, data);

    return root;
}

void preOrderTraverse(Node* root)
{
    if(root == nullptr)
        return;
    cout << root->data << " - ";
    preOrderTraverse(root->left);
    preOrderTraverse(root->right);

}

void inOrderTraverse(Node* root)
{
    if(root == nullptr)
        return;
    inOrderTraverse(root->left);
    cout << root->data << " - ";
    inOrderTraverse(root->right);

}

void postOrderTraverse(Node* root)
{
    if(root == nullptr)
        return;
    postOrderTraverse(root->left);
    postOrderTraverse(root->right);
    cout << root->data << " - ";

}

int main()
{


    root = insertNode(root, 'F');
    root = insertNode(root, 'D');
    root = insertNode(root, 'J');
    root = insertNode(root, 'B');
    root = insertNode(root, 'E');
    root = insertNode(root, 'A');
    root = insertNode(root, 'C');
    root = insertNode(root, 'G');
    root = insertNode(root, 'K');
    root = insertNode(root, 'I');
    root = insertNode(root, 'H');

    cout << "Pre Order Traversal " << endl;
    preOrderTraverse(root);
    cout << endl;

    cout << "In Order Traversal " << endl;
    inOrderTraverse(root);
    cout << endl;

    cout << "Post Order Traversal " << endl;
    postOrderTraverse(root);
    cout << endl;

    return 0;

}
