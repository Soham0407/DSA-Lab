// Reverse a doubly linked list
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *back;
    Node *next;

    Node(int val)
    {
        data = val;
        back = nullptr;
        next = nullptr;
    }
};

Node *reverseDLL(Node *head)
{
    Node *current = head;
    Node *temp = nullptr;

    while (current != nullptr)
    {
        temp = current->back;
        current->back = current->next;
        current->next = temp;

        current = current->back;
    }

    if (temp != nullptr)
        head = temp->back;

    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main()
{
    Node *head = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *fourth = new Node(4);

    head->next = second;
    second->back = head;
    second->next = third;
    third->back = second;
    third->next = fourth;
    fourth->back = third;

    cout << "Original list: ";
    printList(head);

    head = reverseDLL(head);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}
