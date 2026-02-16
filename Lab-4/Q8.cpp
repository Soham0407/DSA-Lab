#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node *mergeSorted(Node *a, Node *b)
{
    if (a==NULL)
        return b;
    if (b==NULL)
        return a;

    if (a->data <= b->data)
    {
        a->next = mergeSorted(a->next, b);
        return a;
    }
    else
    {
        b->next = mergeSorted(a, b->next);
        return b;
    }
}

void display(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    Node *head1 = createNode(1);
    head1->next = createNode(5);
    head1->next->next = createNode(7);

    cout << "List-1: ";
    display(head1);

    Node *head2 = createNode(2);
    head2->next = createNode(3);
    head2->next->next = createNode(9);

    cout << "List-2: ";
    display(head2);
    Node *final = mergeSorted(head1, head2);

    cout << "Merged List: ";
    display(final);
    return 0;
}