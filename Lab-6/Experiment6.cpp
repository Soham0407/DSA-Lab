#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    int currentMin;
    Node *next;
};

Node *topNode = NULL;

void push(int x)
{
    if (x == 0)
        return;
    Node *newNode = new Node;
    newNode->data = x;

    if (topNode == NULL)
        newNode->currentMin = x;
    else
        newNode->currentMin = (x < topNode->currentMin) ? x : topNode->currentMin;

    newNode->next = topNode;
    topNode = newNode;
}

int getMin()
{
    if (topNode == NULL)
    {
        cout << "Stack is empty!\n";
        return -1;
    }
    return topNode->currentMin;
}

int main()
{
    int value;
    char choice;

    do
    {
        cout << "Enter value to push: (0 to exit) ";
        cin >> value;
        push(value);
    } while (value != 0);

    cout << "Minimum Element in Stack: " << getMin() << endl;

    return 0;
}
