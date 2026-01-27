#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

void InsertEnd(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;

    temp->next = newNode;
}

void InsertAtPosition(int k, int value)
{
    if (k < 0)
        return;

    Node *newNode = new Node;
    newNode->data = value;

    if (k == 0)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < k - 1 && temp != nullptr; i++)
        temp = temp->next;

    if (temp == nullptr)
    {
        delete newNode;
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Delete node at position k
void DeleteAtPosition(int k)
{
    if (head == nullptr || k < 0)
        return;

    if (k == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *temp = head;
    for (int i = 0; i < k - 1 && temp->next != nullptr; i++)
        temp = temp->next;

    if (temp->next == nullptr)
        return;

    Node *del = temp->next;
    temp->next = del->next;
    delete del;
}

void PrintList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data;
        if (temp->next)
            cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    InsertEnd(10);
    InsertEnd(20);
    InsertEnd(30);
    InsertEnd(40);

    InsertAtPosition(2, 25);
    DeleteAtPosition(4);

    PrintList();

    return 0;
}
