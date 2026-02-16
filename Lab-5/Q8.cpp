#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *swapNodes(Node *head, int pos1, int pos2)
{
    if (!head || pos1 == pos2)
        return head;

    Node *node1 = head;
    Node *node2 = head;

    for (int i = 1; i < pos1 && node1; i++)
        node1 = node1->next;

    for (int i = 1; i < pos2 && node2; i++)
        node2 = node2->next;

    if (!node1 || !node2)
        return head;

    Node *prev1 = node1->prev;
    Node *next1 = node1->next;
    Node *prev2 = node2->prev;
    Node *next2 = node2->next;

    // Case 1: node1 and node2 are adjacent
    if (node1->next == node2)
    {
        if (prev1)
            prev1->next = node2;
        else
            head = node2;

        node2->prev = prev1;
        node2->next = node1;

        node1->prev = node2;
        node1->next = next2;

        if (next2)
            next2->prev = node1;
    }
    // Case 2: non-adjacent nodes
    else
    {
        if (prev1)
            prev1->next = node2;
        else
            head = node2;

        if (next1)
            next1->prev = node2;

        if (prev2)
            prev2->next = node1;
        else
            head = node1;

        if (next2)
            next2->prev = node1;

        node2->prev = prev1;
        node2->next = next1;

        node1->prev = prev2;
        node1->next = next2;
    }

    return head;
}

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

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
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
    int pos1, pos2;
    cout << "Enter positions to swap: ";
    cin >> pos1 >> pos2;
    head = swapNodes(head, pos1, pos2);
    cout << "List after swapping nodes: ";
    printList(head);

    return 0;
}
