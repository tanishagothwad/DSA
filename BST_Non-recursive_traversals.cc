#include <iostream>
#include <stack>
using namespace std;

struct Node
{
    int rollNo;
    Node *left;
    Node *right;
};

// Insert Student Record into BST
Node* Insert(Node* root, int rollNo)
{
    // Step 1: Check whether the tree is empty
    if (root == NULL)
    {
        // Create a new student record
        Node* newNode = new Node;
        newNode->rollNo = rollNo;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    // Step 2: Compare the roll number with the current node
    if (rollNo < root->rollNo)
    {
        // Insert into the left subtree
        root->left = Insert(root->left, rollNo);
    }
    else if (rollNo > root->rollNo)
    {
        // Insert into the right subtree
        root->right = Insert(root->right, rollNo);
    }
    else
    {
        // Duplicate roll numbers are not allowed
        cout << "Duplicate Roll Number. Record not inserted." << endl;
    }

    // Step 3: Return the updated root
    return root;
}

// Create Student Admission Record BST
Node* CreateBST()
{
    // Step 1: Initialize an empty Binary Search Tree
    Node* root = NULL;

    // Step 2: Read the number of student records
    int n;
    cout << "Enter number of student records: ";
    cin >> n;

    // Step 3: Insert each student's roll number
    for (int i = 1; i <= n; i++)
    {
        int rollNo;
        cout << "Enter roll number: ";
        cin >> rollNo;

        root = Insert(root, rollNo);
    }

    // Step 4: Return the root of the BST
    return root;
}

// Non-Recursive Inorder Traversal
// Left -> Root -> Right
void InorderNonRecursive(Node* root)
{
    // Step 1: Create an empty stack
    stack<Node*> S;

    Node* current = root;

    // Step 2: Continue until all nodes are visited
    while (current != NULL || !S.empty())
    {
        // Move towards the leftmost student record
        while (current != NULL)
        {
            S.push(current);
            current = current->left;
        }

        // Visit the next student record
        current = S.top();
        S.pop();

        cout << current->rollNo << " ";

        // Move to the right subtree
        current = current->right;
    }
}

// Non-Recursive Preorder Traversal
// Root -> Left -> Right
void PreorderNonRecursive(Node* root)
{
    // Step 1: Check whether the BST is empty
    if (root == NULL)
        return;

    // Step 2: Create an empty stack
    stack<Node*> S;

    // Step 3: Push the root node onto the stack
    S.push(root);

    // Step 4: Continue until all records are processed
    while (!S.empty())
    {
        // Remove the top student record
        Node* current = S.top();
        S.pop();

        // Display the current roll number
        cout << current->rollNo << " ";

        // Push the right child first
        if (current->right != NULL)
        {
            S.push(current->right);
        }

        // Push the left child next
        if (current->left != NULL)
        {
            S.push(current->left);
        }
    }
}

// Main Algorithm
int main()
{
    // Step 1: Create the Student Admission Record BST
    Node* root = CreateBST();

    // Step 2: Display student records using Inorder Traversal
    cout << "\nInorder Traversal: ";
    InorderNonRecursive(root);

    // Step 3: Display student records using Preorder Traversal
    cout << "\nPreorder Traversal: ";
    PreorderNonRecursive(root);

    // Step 4: Terminate the program
    return 0;
}