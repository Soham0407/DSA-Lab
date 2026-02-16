#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next;

    Node(int d)
    {
        data = d;
        next = NULL;
    }
};

Node *convert(vector<int> arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
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

Node *getIntersectionNode(Node *head1, Node *head2)
{
    if (!head1 || !head2)
        return NULL;

    Node *p1 = head1;
    Node *p2 = head2;

    while (p1 != p2)
    {
        p1 = (p1 == NULL) ? head2 : p1->next;
        p2 = (p2 == NULL) ? head1 : p2->next;
    }
    return p1;
}

int main()
{
    Node *common = convert({8, 5});

    // List 1: 4 -> 1 -> 8 -> 5
    Node *head1 = convert({4, 1});
    Node *temp = head1;
    while (temp->next)
        temp = temp->next;
    temp->next = common;

    // List 2: 5 -> 6 -> 1 -> 8 -> 5
    Node *head2 = convert({5, 6, 1});
    temp = head2;
    while (temp->next)
        temp = temp->next;
    temp->next = common;

    Node *ans = getIntersectionNode(head1, head2);

    if (ans)
        cout << "Intersection at node with value: " << ans->data << endl;
    else
        cout << "No intersection\n";

    return 0;
}