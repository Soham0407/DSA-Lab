#include<bits/stdc++.h>
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
bool detectCycle(Node *head)
{
    Node *slow = head;
    Node *fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
            return true;
    }
    return false;
}
int main()
{
    Node *head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = head->next; // Creating a cycle for testing

    if (detectCycle(head))
        cout << "Cycle detected in the linked list.\n";
    else
        cout << "No cycle detected in the linked list.\n";

    return 0;
}