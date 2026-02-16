#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    Node *next;
    Node *bottom;

    Node(int x)
    {
        data = x;
        next = nullptr;
        bottom = NULL;
    }
};

Node *merge(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;

    Node *result;

    if (a->data <= b->data)
    {
        result = a;
        result->bottom = merge(a->bottom, b);
    }
    else
    {
        result = b;
        result->bottom = merge(a, b->bottom);
    }

    result->next = nullptr;
    return result;
}

Node *flatten(Node *head)
{
    if (!head || !head->next)
        return head;

    head->next = flatten(head->next);
    head = merge(head, head->next);

    return head;
}

int main()
{
    int n;
    cout << "Enter number of vertical lists: ";
    cin >> n;

    Node *head = nullptr;
    Node *prev = nullptr;

    for (int i = 0; i < n; i++)
    {
        int m;
        cout << "Enter number of elements in vertical list ";
        cin >> m;

        Node *verticalHead = nullptr;
        Node *verticalPrev = nullptr;

        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;

            Node *newNode = new Node(x);

            if (!verticalHead)
                verticalHead = newNode;
            else
                verticalPrev->bottom = newNode;

            verticalPrev = newNode;
        }

        if (!head)
            head = verticalHead;
        else
            prev->next = verticalHead;

        prev = verticalHead;
    }

    head = flatten(head);

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->bottom;
    }

    return 0;
}
