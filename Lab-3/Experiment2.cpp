#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *head = nullptr;

void InsertFront(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void Undo()
{
    if (head == nullptr)
        return;

    Node *temp = head;
    head = head->next;
    delete temp;
}

void PrintList()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    InsertFront(10);
    InsertFront(20);
    InsertFront(30);
    InsertFront(40);
    PrintList();
    InsertFront(50);
    Undo();
    PrintList();

    return 0;
}
