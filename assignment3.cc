#include <iostream>
#include <queue>
using namespace std;

// Structure of BST Node
struct Node
{
    int data;
    Node *left;
    Node *right;
};

// Insert Employee ID into BST
Node* insert(Node* root, int value)
{
    if (root == NULL)
    {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->left = NULL;
        newNode->right = NULL;

        return newNode;
    }

    if (value < root->data)
    {
        root->left = insert(root->left, value);
    }
    else if (value > root->data)
    {
        root->right = insert(root->right, value);
    }
    else
    {
        cout << "Duplicate Employee ID not allowed!" << endl;
    }

    return root;
}

// Level Order Traversal
void levelOrder(Node* root)
{
    if (root == NULL)
    {
        cout << "Tree is Empty" << endl;
        return;
    }

    queue<Node*> q;
    q.push(root);

    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();

        cout << temp->data << " ";

        if (temp->left != NULL)
            q.push(temp->left);

        if (temp->right != NULL)
            q.push(temp->right);
    }

    cout << endl;
}

// Copy BST
Node* copyTree(Node* root)
{
    if (root == NULL)
        return NULL;

    Node* newNode = new Node;

    newNode->data = root->data;
    newNode->left = copyTree(root->left);
    newNode->right = copyTree(root->right);

    return newNode;
}

// Find Height of BST
int height(Node* root)
{
    if (root == NULL)
        return -1;

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    if (leftHeight > rightHeight)
        return leftHeight + 1;
    else
        return rightHeight + 1;
}

// Print Leaf Nodes
void printLeafNodes(Node* root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        cout << root->data << " ";
        return;
    }

    printLeafNodes(root->left);
    printLeafNodes(root->right);
}

// Main Function
int main()
{
    Node* root = NULL;
    Node* copyRoot = NULL;

    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << " Employee Database Analysis using BST\n";
        cout << "=====================================\n";
        cout << "1. Insert Employee IDs\n";
        cout << "2. Display Original BST (Level Order)\n";
        cout << "3. Copy BST\n";
        cout << "4. Display Copied BST (Level Order)\n";
        cout << "5. Find Height of BST\n";
        cout << "6. Display Leaf Nodes\n";
        cout << "7. Exit\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
            {
                int n, value;

                cout << "Enter number of employee IDs: ";
                cin >> n;

                for (int i = 1; i <= n; i++)
                {
                    cout << "Enter Employee ID: ";
                    cin >> value;

                    root = insert(root, value);
                }

                break;
            }

            case 2:
                cout << "Original BST (Level Order): ";
                levelOrder(root);
                break;

            case 3:
                copyRoot = copyTree(root);
                cout << "BST Copied Successfully" << endl;
                break;

            case 4:
                cout << "Copied BST (Level Order): ";
                levelOrder(copyRoot);
                break;

            case 5:
                cout << "Height of BST = " << height(root) << endl;
                break;

            case 6:
                cout << "Leaf Nodes: ";
                printLeafNodes(root);
                cout << endl;
                break;

            case 7:
                cout << "Exiting Program..." << endl;
                break;

            default:
                cout << "Invalid Choice" << endl;
        }

    } while (choice != 7);

    return 0;
}