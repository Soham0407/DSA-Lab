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

void DeleteNthFromEnd(int N)
{
    Node *fast = head;
    Node *slow = head;

    for (int i = 0; i < N; i++)
    {
        if (fast == nullptr)
            return; // N > length
        fast = fast->next;
    }
    if (fast == nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }
    while (fast->next != nullptr)
    {
        fast = fast->next;
        slow = slow->next;
    }

    Node *temp = slow->next;
    slow->next = temp->next;
    delete temp;
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
    InsertEnd(1);
    InsertEnd(2);
    InsertEnd(3);
    InsertEnd(4);
    InsertEnd(5);

    int N = 2;
    DeleteNthFromEnd(N);

    PrintList();

    return 0;
}
