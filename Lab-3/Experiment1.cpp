#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int value)
{
    Node *newNode = new Node;
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(Node *&head, int value)
{
    Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
}

void insertAtTail(Node *&head, int value)
{
    Node *newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}

void deleteByValue(Node *&head, int value)
{
    if (head == NULL)
        return;

    if (head->data == value)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *curr = head;
    while (curr->next != NULL && curr->next->data != value)
        curr = curr->next;

    if (curr->next != NULL)
    {
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

void deleteByPosition(Node *&head, int pos)
{
    if (head == NULL || pos < 0)
        return;

    if (pos == 0)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *curr = head;
    for (int i = 0; i < pos - 1 && curr->next != NULL; i++)
        curr = curr->next;

    if (curr->next != NULL)
    {
        Node *temp = curr->next;
        curr->next = temp->next;
        delete temp;
    }
}

bool search(Node *head, int value)
{
    while (head != NULL)
    {
        if (head->data == value)
            return true;
        head = head->next;
    }
    return false;
}

void reverseList(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = NULL;

    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

void displayList(Node *head)
{
    if (head == NULL)
    {
        cout << "List is empty\n";
        return;
    }

    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

int main()
{
    Node *head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    deleteByValue(head, 20);
    reverseList(head);
    displayList(head);

    return 0;
}
