#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *prev;
    Node *next;
    Node *random;

    Node(int d)
    {
        data = d;
        prev = next = random = NULL;
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
        temp->prev = curr;
        curr = temp;
    }
    return head;
}

void display(Node *head)
{
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }
    cout << "NULL\n";
}

Node *reverseDLL(Node *head)
{
    Node *temp = NULL;
    Node *curr = head;
    while (curr)
    {
        temp = curr->prev;
        curr->prev = curr->next;
        curr->next = temp;
        curr = curr->prev;
    }
    if (temp)
        head = temp->prev;
    return head;
}

void pairSum(Node *head, int sum)
{
    Node *left = head;
    Node *right = head;
    while (right->next)
        right = right->next;

    cout << "Pairs with sum " << sum << ":\n";
    while (left != right && right->next != left)
    {
        int s = left->data + right->data;
        if (s == sum)
        {
            cout << "(" << left->data << ", " << right->data << ")\n";
            left = left->next;
            right = right->prev;
        }
        else if (s < sum)
            left = left->next;
        else
            right = right->prev;
    }
}

Node *rotateByK(Node *head, int k)
{
    if (!head || k == 0)
        return head;
    Node *curr = head;
    int count = 1;
    while (count < k && curr)
    {
        curr = curr->next;
        count++;
    }
    if (!curr)
        return head;

    Node *kth = curr;
    while (curr->next)
        curr = curr->next;

    curr->next = head;
    head->prev = curr;

    head = kth->next;
    head->prev = NULL;
    kth->next = NULL;

    return head;
}

Node *deleteDuplicates(Node *head)
{
    unordered_map<int, int> freq;
    Node *curr = head;
    while (curr)
    {
        freq[curr->data]++;
        curr = curr->next;
    }

    curr = head;
    while (curr)
    {
        Node *nextNode = curr->next;
        if (freq[curr->data] > 1)
        {
            if (curr->prev)
                curr->prev->next = curr->next;
            else
                head = curr->next;

            if (curr->next)
                curr->next->prev = curr->prev;
            delete curr;
        }
        curr = nextNode;
    }
    return head;
}

bool isPalindrome(Node *head)
{
    Node *left = head;
    Node *right = head;
    while (right->next)
        right = right->next;
    while (left != right && right->next != left)
    {
        if (left->data != right->data)
            return false;
        left = left->next;
        right = right->prev;
    }
    return true;
}

Node *mergeSorted(Node *a, Node *b)
{
    if (!a)
        return b;
    if (!b)
        return a;
    if (a->data < b->data)
    {
        a->next = mergeSorted(a->next, b);
        if (a->next)
            a->next->prev = a;
        a->prev = NULL;
        return a;
    }
    else
    {
        b->next = mergeSorted(a, b->next);
        if (b->next)
            b->next->prev = b;
        b->prev = NULL;
        return b;
    }
}

Node *swapNodes(Node *head, int x, int y)
{
    if (x == y)
        return head;
    Node *n1 = head, *n2 = head;
    for (int i = 1; i < x; i++)
        n1 = n1->next;
    for (int i = 1; i < y; i++)
        n2 = n2->next;
    swap(n1->data, n2->data);
    return head;
}

Node *cloneDLL(Node *head)
{
    unordered_map<Node *, Node *> mp;
    Node *curr = head;
    while (curr)
    {
        mp[curr] = new Node(curr->data);
        curr = curr->next;
    }

    curr = head;
    while (curr)
    {
        mp[curr]->next = mp[curr->next];
        mp[curr]->prev = mp[curr->prev];
        mp[curr]->random = mp[curr->random];
        curr = curr->next;
    }
    return mp[head];
}

int main()
{
    cout << "Enter elements of DLL separated by space (end with -1):\n";
    vector<int> arr;
    int val;
    while (cin >> val && val != -1)
        arr.push_back(val);

    Node *head = convert(arr);

    int choice;
    do
    {
        cout << "\n---- DOUBLY LINKED LIST MENU ----\n";
        cout << "1. Reverse DLL\n2. Find pair with sum\n3. Rotate by k nodes\n";
        cout << "4. Delete all duplicates\n5. Palindrome check\n";
        cout << "6. Merge two sorted DLLs\n7. Swap nodes\n8. Clone DLL with random pointer\n0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            head = reverseDLL(head);
            cout << "List is: ";
            display(head);
            break;
        case 2:
        {
            int sum;
            cout << "Enter sum: ";
            cin >> sum;
            pairSum(head, sum);
            break;
        }
        case 3:
        {
            int k;
            cout << "Enter k: ";
            cin >> k;
            head = rotateByK(head, k);
            cout << "List is: ";
            display(head);
            break;
        }
        case 4:
            head = deleteDuplicates(head);
            cout << "List is: ";
            display(head);
            break;
        case 5:
            if (isPalindrome(head))
                cout << "DLL is a PALINDROME.\n";
            else
                cout << "DLL is NOT a palindrome.\n";
            break;
        case 6:
        {
            cout << "Enter second sorted DLL (end with -1):\n";
            vector<int> arr2;
            int v;
            while (cin >> v && v != -1)
                arr2.push_back(v);
            Node *head2 = convert(arr2);
            head = mergeSorted(head, head2);
            cout << "List is: ";
            display(head);
            break;
        }
        case 7:
        {
            int x, y;
            cout << "Enter positions x and y: ";
            cin >> x >> y;
            head = swapNodes(head, x, y);
            cout << "List is: ";
            display(head);
            break;
        }
        case 8:
        {
            Node *clone = cloneDLL(head);
            cout << "Original DLL: ";
            display(head);
            cout << "Cloned DLL:   ";
            display(clone);
            break;
        }
        case 0:
            cout << "Exitingn";
            break;
        default:
            cout << "Invalid choice.\n";
        }
    } while (choice != 0);

    return 0;
}