#include <bits/stdc++.h>
using namespace std;

struct NODE
{
    int data;
    NODE *next;
};

bool detectCycle(NODE *head)
{
    NODE *slow = head;
    NODE *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}

void removeCycle(NODE *head)
{
    NODE *slow = head;
    NODE *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            break;
    }

    if (fast == NULL || fast->next == NULL)
        return;

    slow = head;
    while (slow != fast)
    {
        slow = slow->next;
        fast = fast->next;
    }

    NODE *temp = slow;
    while (temp->next != slow)
        temp = temp->next;

    temp->next = NULL;
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
    head->data = 10;

    NODE *second = new NODE();
    second->data = 20;

    NODE *third = new NODE();
    third->data = 30;

    NODE *fourth = new NODE();
    fourth->data = 40;

    NODE *fifth = new NODE();
    fifth->data = 50;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    fifth->next = third;

    if (detectCycle(head))
        cout << "Cycle detected\n";
    else
        cout << "No cycle\n";

    removeCycle(head);
    display(head);

    return 0;
}