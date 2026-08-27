#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
};

Node* head = NULL;

// 1. Insert at Beginning
void insertBeginning(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = head;

    head = newNode;

    cout << "Node inserted at beginning." << endl;
}

// 2. Insert at End
void insertEnd(int value)
{
    Node* newNode = new Node();

    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Node inserted at end." << endl;
}

// 3. Delete from Beginning
void deleteBeginning()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;

    cout << "Node deleted from beginning." << endl;
}

// 4. Display
void display()
{
    if (head == NULL)
    {
        cout << "List is empty." << endl;
        return;
    }

    Node* temp = head;

    cout << "Linked List: ";

    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }

    cout << "NULL" << endl;
}

// Main Function
int main()
{
    int choice, value;

    do
    {
        cout << "\n----- SINGLY LINKED LIST -----" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "3. Delete from Beginning" << endl;
        cout << "4. Display" << endl;
        cout << "5. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter book ID: ";
                cin >> value;
                insertBeginning(value);
                break;

            case 2:
                cout << "Enter book ID: ";
                cin >> value;
                insertEnd(value);
                break;

            case 3:
                deleteBeginning();
                break;

            case 4:
                display();
                break;

            case 5:
                cout << "Exiting program..." << endl;
                break;

            default:
                cout << "Invalid choice!" << endl;
        }

    } while (choice != 5);

    return 0;
}