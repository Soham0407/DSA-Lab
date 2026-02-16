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

void deleteDuplicates(Node *head)
{
    for (Node *curr = head; curr != NULL; curr = curr->next)
    {
        Node *runner = curr->next;

        while (runner != NULL)
        {
            if (runner->data == curr->data)
            {
                Node *dup = runner;
                runner = runner->next;

                if (dup->prev)
                    dup->prev->next = dup->next;
                if (dup->next)
                    dup->next->prev = dup->prev;

                delete dup;
            }
            else
            {
                runner = runner->next;
            }
        }
    }
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
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

    deleteDuplicates(head);

    cout << "List after deleting duplicates:\n";
    printList(head);

    return 0;
}
