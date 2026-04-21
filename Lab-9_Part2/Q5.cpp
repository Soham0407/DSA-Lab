#include <iostream>
using namespace std;

int main()
{
    int size, n;

    cout << "Enter hash table size: ";
    cin >> size;

    int table[size];
    for (int i = 0; i < size; i++)
        table[i] = -1;

    cout << "Enter number of keys: ";
    cin >> n;

    int keys[n];
    cout << "Enter keys:\n";
    for (int i = 0; i < n; i++)
        cin >> keys[i];

    for (int i = 0; i < n; i++)
    {
        int key = keys[i];
        int index = key % size;

        int j = 0;
        while (table[(index + j * j) % size] != -1)
        {
            j++;
        }

        table[(index + j * j) % size] = key;
    }

    cout << "\nHash Table:\n";
    for (int i = 0; i < size; i++)
    {
        cout << i << " -> " << table[i] << endl;
    }

    return 0;
}