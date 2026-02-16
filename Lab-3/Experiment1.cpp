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

Node *reverseList(Node *s)
{
    if (s == NULL)
        return s;

    if (s->next == NULL)
    {
        printf("single node");
        return s;
    }

    if (s->next->next == NULL)
    {
        Node *p = s;
        Node *q = s->next;

        q->next = p;
        p->next = NULL;

        return q;
    }

    Node *p = s;
    Node *q = s->next;
    p->next = NULL;

    while (q != NULL)
    {
        Node *r = q->next;

        q->next = p;

        p = q;
        q = r;
    }

    return p;
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
    int choice, value, pos;

    do
    {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insert at Head\n";
        cout << "2. Insert at Tail\n";
        cout << "3. Delete by Value\n";
        cout << "4. Delete by Position\n";
        cout << "5. Search\n";
        cout << "6. Reverse List\n";
        cout << "7. Detect Cycle\n";
        cout << "8. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value: ";
            cin >> value;
            insertAtHead(head, value);
            break;

        case 2:
            cout << "Enter value: ";
            cin >> value;
            insertAtTail(head, value);
            break;

        case 3:
            cout << "Enter value to delete: ";
            cin >> value;
            deleteByValue(head, value);
            break;

        case 4:
            cout << "Enter position (0-based): ";
            cin >> pos;
            deleteByPosition(head, pos);
            break;

        case 5:
            cout << "Enter value to search: ";
            cin >> value;
            if (search(head, value))
                cout << "Value found\n";
            else
                cout << "Value not found\n";
            break;

        case 6:
            head = reverseList(head);
            cout << "List reversed\n";
            break;

        case 7:
            if (detectCycle(head))
                cout << "Cycle detected\n";
            else
                cout << "No cycle detected\n";
            break;

        case 8:
            displayList(head);
            break;

        case 0:
            cout << "Exiting";
            break;

        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}
