#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

Node *mergeTwoLists(Node *l1, Node *l2)
{
    if (!l1)
        return l2;
    if (!l2)
        return l1;

    Node *result = NULL;

    if (l1->data < l2->data)
    {
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    }
    else
    {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }

    return result;
}

Node *mergeKLists(Node *lists[], int k)
{
    if (k == 0)
        return NULL;

    Node *result = lists[0];

    for (int i = 1; i < k; i++)
    {
        result = mergeTwoLists(result, lists[i]);
    }

    return result;
}

void printList(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main()
{
    int k = 3;

    Node *l1 = new Node(1);
    l1->next = new Node(4);
    l1->next->next = new Node(5);

    Node *l2 = new Node(1);
    l2->next = new Node(3);
    l2->next->next = new Node(4);

    Node *l3 = new Node(2);
    l3->next = new Node(6);

    Node *lists[] = {l1, l2, l3};

    Node *result = mergeKLists(lists, k);

    cout << "Merged List: ";
    printList(result);

    return 0;
}