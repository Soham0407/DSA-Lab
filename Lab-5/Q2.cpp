#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void insertEnd(Node *&head, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    if (!head)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

void findPairs(Node *head, int X)
{
    if (head == NULL)
        return;

    Node *left = head;
    Node *right = head;

    while (right->next != NULL)
        right = right->next;

    bool found = false;

    while (left != right && right->next != left)
    {
        int sum = left->data + right->data;

        if (sum == X)
        {
            cout << left->data << ", " << right->data << endl;
            found = true;
            left = left->next;
            right = right->prev;
        }
        else if (sum < X)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }

    if (!found)
        cout << "No pair found\n";
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertEnd(head, x);
    }

    cout << "Enter the sum: ";
    int X;
    cin >> X;
    cout << "Original List:\n";
    printList(head);

    findPairs(head, X);
    return 0;
}
