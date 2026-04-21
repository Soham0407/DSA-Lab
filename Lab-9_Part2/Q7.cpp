#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

int hashFunction(int key, int size)
{
    return key % size;
}

void insert(Node *table[], int size, int key)
{
    int index = hashFunction(key, size);

    Node *newNode = new Node;
    newNode->data = key;
    newNode->next = table[index];

    table[index] = newNode;
}

void display(Node *table[], int size)
{
    cout << "\nHash Table:\n";

    for (int i = 0; i < size; i++)
    {
        cout << i << " --> ";

        Node *temp = table[i];
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }

        cout << "NULL" << endl;
    }
}

int main()
{
    int size, n;

    cout << "Enter size of hash table: ";
    cin >> size;

    Node *table[size];
    for (int i = 0; i < size; i++)
    {
        table[i] = NULL;
    }

    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;
        insert(table, size, key);
    }

    display(table, size);

    return 0;
}