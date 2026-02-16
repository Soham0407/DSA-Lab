#include <iostream>
using namespace std;

struct node
{
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

node *moveLastToFront(node *head)
{
    if (!head || !head->next)
        return head;

    node *prev = nullptr;
    node *curr = head;

    while (curr->next)
    {
        prev = curr;
        curr = curr->next;
    }

    prev->next = nullptr;
    curr->next = head;
    head = curr;

    return head;
}

void printList(node *head)
{
    while (head)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL";
}

int main()
{
    node *head = nullptr;

    head = new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);
    cout << "Before: ";
    printList(head);

    head = moveLastToFront(head);

    cout << "\nAfter:  ";
    printList(head);

    return 0;
}
