#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
};
Node *front = NULL, *rear = NULL;

Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void enQueue(int data)
{
    Node *newNode = createNode(data);
    if (front == NULL)
    {
        rear = front = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
        rear->next = front;
    }
}

void deQueue()
{
    Node *temp = front;
    if (front == rear)
    {
        front = rear = NULL;
    }
    else
    {
        front = front->next;
        rear->next = front;
    }
}

void Front()
{
    if (front != NULL)
        cout << "Front element: " << front->data << endl;
    else
        cout << "Queue is empty\n";
}

void Rear()
{
    if (rear != NULL)
        cout << "Rear element: " << rear->data << endl;
    else
        cout << "Queue is empty\n";
}

void display()
{
    if (front == NULL)
    {
        cout << "Queue is empty\n";
        return;
    }
    Node *temp = front;
    cout << "Queue: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

int main()
{
    int choice;
    while (choice != 6)
    {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Front\n4. Rear\n5. Display\n6. Exit\nEnter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int data;
            cout << "Enter the data to Enqueue: ";
            cin >> data;
            enQueue(data);
            break;
        case 2:
            deQueue();
            break;
        case 3:
            Front();
            break;
        case 4:
            Rear();
            break;
        case 5:
            display();
            break;
        case 6:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid choice\n";
        }
    }
}