#include <iostream>
using namespace std;

// Node structure
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Create a new node
Node* createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Create Binary Tree
Node* createTree()
{
    int value;

    cout << "Enter value (-1 for no node): ";
    cin >> value;

    if (value == -1)
        return NULL;

    Node* root = createNode(value);

    cout << "Enter left child of " << value << endl;
    root->left = createTree();

    cout << "Enter right child of " << value << endl;
    root->right = createTree();

    return root;
}

// Inorder Traversal
void inorder(Node* root)
{
    if (root == NULL)
        return;

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Preorder Traversal
void preorder(Node* root)
{
    if (root == NULL)
        return;

    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

// Postorder Traversal
void postorder(Node* root)
{
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{
    Node* root = NULL;
    int choice;

    // Create tree
    cout << "===== CREATE BINARY TREE =====" << endl;
    root = createTree();

    // Menu
    do
    {
        cout << "\n===== BINARY TREE MENU =====" << endl;
        cout << "1. Inorder Traversal" << endl;
        cout << "2. Preorder Traversal" << endl;
        cout << "3. Postorder Traversal" << endl;
        cout << "4. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch(choice)
        {
            case 1:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;

            case 2:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;

            case 3:
                cout << "Postorder Traversal: ";
                postorder(root);
                cout << endl;
                break;

            case 4:
                cout << "Exiting..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while(choice != 4);

    return 0;
} 