#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

NODE *reverseInGroups(NODE *head, int k)
{
    if (head == NULL || k <= 1)
        return head;

    NODE dummy;
    dummy.next = head;
    NODE *prevGroup = &dummy;

    while (true)
    {
        NODE *kth = prevGroup;
        for (int i = 0; i < k && kth != NULL; i++)
            kth = kth->next;

        if (kth == NULL)
            break;

        NODE *groupNext = kth->next;
        NODE *prev = groupNext;
        NODE *curr = prevGroup->next;

        while (curr != groupNext)
        {
            NODE *nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }

        NODE *temp = prevGroup->next;
        prevGroup->next = kth;
        prevGroup = temp;
    }

    return dummy.next;
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

    int k;
    cout << "Enter the value of k: ";
    cin >> k;
    head = reverseInGroups(head, k);

    cout << "After reversing in groups of " << k << ": ";
    display(head);

    return 0;
}