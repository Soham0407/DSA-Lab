#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

Node *mergeSorted(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    Node *head = nullptr;
    Node *tail = nullptr;

    if (head1->data <= head2->data)
    {
        head = tail = head1;
        head1 = head1->next;
    }
    else
    {
        head = tail = head2;
        head2 = head2->next;
    }
    tail->prev = nullptr;

    while (head1 && head2)
    {
        if (head1->data <= head2->data)
        {
            tail->next = head1;
            head1->prev = tail;
            head1 = head1->next;
        }
        else
        {
            tail->next = head2;
            head2->prev = tail;
            head2 = head2->next;
        }
        tail = tail->next;
    }

    if (head1)
    {
        tail->next = head1;
        head1->prev = tail;
    }
    else if (head2)
    {
        tail->next = head2;
        head2->prev = tail;
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
    Node *head1 = nullptr;

    int n1, n2;
    cout << "Enter number of nodes in DLL1 and DLL2: ";
    cin >> n1 >> n2;

    cout << "Enter elements of 1st DLL: ";
    for (int i = 0; i < n1; i++)
    {
        int x;
        cin >> x;
        insertEnd(head1, x);
    }

    Node *head2 = nullptr;
    cout << "Enter elements of 2nd DLL: ";
    for (int i = 0; i < n2; i++)
    {
        int x;
        cin >> x;
        insertEnd(head2, x);
    }

    Node *mergedHead = mergeSorted(head1, head2);
    cout << "Merged List: ";
    printList(mergedHead);

    return 0;
}
