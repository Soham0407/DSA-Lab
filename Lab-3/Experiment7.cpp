#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

NODE *reverseInGroups(NODE *head, int k)
{
    if (head == NULL)
        return NULL;

    NODE *curr = head;
    NODE *prev = NULL;
    NODE *next = NULL;
    int count = 0;

    while (curr != NULL && count < k)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    if (next != NULL)
        head->next = reverseInGroups(next, k);

    return prev;
}

void display(NODE *head)
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
    NODE *head = new NODE();
    head->data = 1;

    NODE *second = new NODE();
    second->data = 2;

    NODE *third = new NODE();
    third->data = 3;

    NODE *fourth = new NODE();
    fourth->data = 4;

    NODE *fifth = new NODE();
    fifth->data = 5;

    NODE *sixth = new NODE();
    sixth->data = 6;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = NULL;

    cout << "Original List: ";
    display(head);

    int k = 3;
    head = reverseInGroups(head, k);

    cout << "After reversing in groups of " << k << ": ";
    display(head);

    return 0;
}