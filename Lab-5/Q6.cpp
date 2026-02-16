#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
};

void insertEnd(Node *&head, int data)
{
    Node *newNode = new Node{data, nullptr, nullptr};

    if (!head)
    {
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next)
        temp = temp->next;

    temp->next = newNode;
    newNode->prev = temp;
}

bool isPalindrome(Node *head)
{
    if (!head || !head->next)
        return true;

    Node *tail = head;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }

    Node *left = head;
    Node *right = tail;

    while (left != right && left->prev != right)
    {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }

    return true;
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
    Node *head = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        insertEnd(head, x);
    }

    cout << "Original List:\n";
    printList(head);

    if (isPalindrome(head))
        cout << "The list is a palindrome.\n";
    else
        cout << "The list is not a palindrome.\n";

    return 0;
}
