#include <iostream>
using namespace std;

// First hash function
int h1(int key, int size)
{
    return key % size;
}

int h2(int key, int size)
{
    return 1 + (key % (size - 1));
}

// Insert using double hashing
void insert(int table[], int size, int key)
{
    int index = h1(key, size);

    // If no collision
    if (table[index] == -1)
    {
        table[index] = key;
        return;
    }

    // Collision occurred → use double hashing
    int step = h2(key, size);
    int i = 1;

    while (table[(index + i * step) % size] != -1)
    {
        i++;
        if (i == size)
        {
            cout << "Hash table is full, cannot insert " << key << endl;
            return;
        }
    }

    table[(index + i * step) % size] = key;
}

void display(int table[], int size)
{
    cout << "\nHash Table:\n";
    for (int i = 0; i < size; i++)
    {
        cout << i << " --> ";
        if (table[i] == -1)
            cout << "EMPTY";
        else
            cout << table[i];
        cout << endl;
    }
}

int main()
{
    int size, n;

    cout << "Enter size of hash table: ";
    cin >> size;

    int table[size];
    for (int i = 0; i < size; i++)
    {
        table[i] = -1;
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