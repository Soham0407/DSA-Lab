#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

int findMiddle(Node *head)
{
    if (head == NULL)
        return -1;

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    int mid = count / 2;
    temp = head;

    for (int i = 0; i < mid; i++)
    {
        temp = temp->next;
    }

    return temp->data;
}

int main()
{
    Node *head = new Node(11);
    head->next = new Node(22);
    head->next->next = new Node(33);
    head->next->next->next = new Node(44);
    head->next->next->next->next = new Node(55);

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\nMiddle element = " << findMiddle(head);

    return 0;
}
