#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *front = NULL, *rear = NULL;
Node *createNde(int data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void Enque(int data)
{
    Node *newNode = createNde(data);
    if (rear == NULL)
    {
        rear = newNode;
        front = rear;
        return;
    }
    rear->next = newNode;
    rear = newNode;
}

Node *Dequeue(Node *&front)
{
    if (front == NULL)
    {
        cout << "Queue is Empty\n";
        return NULL;
    }
    Node *temp = front;
    front = front->next;
    delete temp;
    return front;
}

Node *isEmpty(Node *&front)
{
    if (front == NULL)
    {
        cout << "Queue is Empty\n";
        return NULL;
    }
    cout << "Queue is not Empty\n";
    return front;
}

Node *Front(Node *&front)
{
    if (front == NULL)
    {
        cout << "Queue is Empty\n";
        return NULL;
    }
    cout << "Front Element: " << front->data << endl;
    return front;
}

void display(Node *front)
{
    if (front == NULL)
    {
        cout << "Queue is Empty\n";
        return;
    }
    Node *temp = front;
    cout << "Queue Elements: ";
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    int choice, data;
    do
    {
        cout << "Enter the task to perform: \n1. Enqueue\n2. Dequeue\n3. Check if Queue is Empty\n4. Get Front Element\n5. Display Queue\n0. Exit\n";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the data to Enqueue: ";
            cin >> data;
            Enque(data);
            break;
        case 2:
            front = Dequeue(front);
            break;
        case 3:
            front = isEmpty(front);
            break;
        case 4:
            front = Front(front);
            break;
        case 5:
            display(front);
            break;
        case 0:
            cout << "Exit\n";
            break;
        default:
            cout << "Invalid Choice\n";
        }
    } while (choice != 0);
}