#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    int priority;
    Node *next;
};
Node *front = NULL;
Node *createNode(int data, int priority)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->priority = priority;
    newNode->next = NULL;
    return newNode;
}

void Push(int data, int priority)
{
    Node *newNode = createNode(data, priority);
    if (front == NULL || priority < front->priority)
    {
        newNode->next = front;
        front = newNode;
    }
    else
    {
        Node *temp = front;
        while (temp->next != NULL && temp->next->priority < priority)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
}

void Pop()
{
    Node *temp = front;
    front = front->next;
    int value = temp->data;
    delete temp;
    cout << "The value popped is: " << value << endl;
}

void Peek()
{
    cout << "The top element of the priority queue is: " << front->data;
}

void Display()
{
    Node *temp = front;
    cout << "Priority Queue: ";
    while (temp != NULL)
    {
        cout << temp->data << "(priority: " << temp->priority << ") ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    int choice;
    while (choice != 4)
    {
        cout << "1. Push\n2. Pop\n3. Peek\n4. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data, priority;
            cout << "Enter the data and its priority: ";
            cin >> data >> priority;
            Push(data, priority);
            break;
        case 2:
            Pop();
            break;
        case 3:
            Peek();
            break;
        case 4:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    }
}