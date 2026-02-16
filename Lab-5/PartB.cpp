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
    if (arr.empty())
        return NULL;

    Node *head = new Node(arr[0]);
    Node *curr = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        curr->next = temp;
        curr = temp;
    }
    curr->next = head;
    return head;
}

void display(Node *head)
{
    if (!head)
    {
        cout << "List is empty\n";
        return;
    }
    Node *curr = head;
    do
    {
        cout << curr->data << " ";
        curr = curr->next;
    } while (curr != head);
    cout << "(back to " << head->data << ")\n";
}

pair<Node *, Node *> splitList(Node *head)
{
    if (!head || head->next == head)
        return {head, NULL};

    Node *slow = head;
    Node *fast = head->next;

    while (fast != head && fast->next != head)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    Node *head1 = head;
    Node *head2 = slow->next;
    slow->next = head1;

    Node *temp = head2;
    while (temp->next != head)
        temp = temp->next;
    temp->next = head2;

    return {head1, head2};
}

bool isSorted(Node *head)
{
    if (!head || head->next == head)
        return true;
    Node *curr = head;
    do
    {
        if (curr->data > curr->next->data && curr->next != head)
            return false;
        curr = curr->next;
    } while (curr != head);
    return true;
}

Node *insertSorted(Node *head, int val)
{
    Node *newNode = new Node(val);
    if (!head)
    {
        newNode->next = newNode;
        return newNode;
    }

    Node *curr = head;
    Node *prev = NULL;

    do
    {
        if (curr->data >= val)
            break;
        prev = curr;
        curr = curr->next;
    } while (curr != head);

    newNode->next = curr;
    if (!prev)
    {
        Node *tail = head;
        while (tail->next != head)
            tail = tail->next;
        tail->next = newNode;
        head = newNode;
    }
    else
        prev->next = newNode;

    return head;
}

Node *reverseCLL(Node *head)
{
    if (!head || head->next == head)
        return head;

    Node *prev = NULL;
    Node *curr = head;
    Node *nextNode;

    do
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    } while (curr != head);

    head->next = prev;
    head = prev;
    return head;
}

Node *deleteEveryK(Node *head, int k)
{
    if (!head || head->next == head || k <= 0)
        return head;

    Node *curr = head;
    Node *prev = NULL;

    while (curr->next != curr)
    {
        for (int count = 1; count < k; count++)
        {
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        Node *temp = curr;
        curr = curr->next;
        delete temp;
    }

    return curr;
}

Node *circularToLinear(Node *head)
{
    if (!head)
        return NULL;
    Node *curr = head;
    while (curr->next != head)
        curr = curr->next;
    curr->next = NULL;
    return head;
}

Node *mergeCLL(Node *head1, Node *head2)
{
    if (!head1)
        return head2;
    if (!head2)
        return head1;

    Node *tail1 = head1;
    while (tail1->next != head1)
        tail1 = tail1->next;

    Node *tail2 = head2;
    while (tail2->next != head2)
        tail2 = tail2->next;

    tail1->next = head2;
    tail2->next = head1;

    return head1;
}

int countNodesLoop(Node *head)
{
    if (!head)
        return 0;
    Node *slow = head;
    Node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            int count = 1;
            Node *temp = slow->next;
            while (temp != slow)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }
    }
    return 0;
}

int main()
{
    cout << "Enter elements of Circular Linked List (-1 to end):\n";
    vector<int> arr;
    int val;
    while (cin >> val && val != -1)
        arr.push_back(val);

    Node *head = convert(arr);

    int choice;
    do
    {
        cout << "\n---- CIRCULAR LINKED LIST MENU ----\n";
        cout << "1. Split list\n2. Check sorted\n3. Insert into sorted list\n";
        cout << "4. Reverse list\n5. Delete every k-th node\n6. Convert to linear\n";
        cout << "7. Last remaining node\n8. Merge two CLLs\n9. Detect & count loop\n0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            auto halves = splitList(head);
            cout << "First Half: ";
            display(halves.first);
            cout << "Second Half: ";
            display(halves.second);
            break;
        }
        case 2:
            if (isSorted(head))
                cout << "CLL is SORTED.\n";
            else
                cout << "CLL is NOT sorted.\n";
            break;
        case 3:
        {
            int x;
            cout << "Enter value to insert: ";
            cin >> x;
            head = insertSorted(head, x);
            cout << "List is: ";
            display(head);
            break;
        }
        case 4:
            head = reverseCLL(head);
            cout << "List is: ";
            display(head);
            break;
        case 5:
        {
            int k;
            cout << "Enter k: ";
            cin >> k;
            head = deleteEveryK(head, k);
            cout << "Remaining node: " << head->data << endl;
            break;
        }
        case 6:
            head = circularToLinear(head);
            cout << "List is: ";
            display(head);
            break;
        case 7:
            cout << "Last remaining node: " << head->data << endl;
            break;
        case 8:
        {
            cout << "Enter second circular list (-1 to end):\n";
            vector<int> arr2;
            int v;
            while (cin >> v && v != -1)
                arr2.push_back(v);
            Node *head2 = convert(arr2);
            head = mergeCLL(head, head2);
            cout << "List is: ";
            display(head);
            break;
        }
        case 9:
            cout << "Nodes in loop: " << countNodesLoop(head) << endl;
            break;
        case 0:
            cout << "Exit";
            break;
        default:
            cout << "Invalid choice\n";
        }

    } while (choice != 0);

    return 0;
}