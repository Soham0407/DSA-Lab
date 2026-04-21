#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int m, n;
    double A = 0.5;

    cout << "Enter hash table size (m): ";
    cin >> m;

    vector<vector<int>> hashTable(m);

    cout << "Enter number of keys: ";
    cin >> n;

    cout << "Enter keys: ";
    for (int i = 0; i < n; i++)
    {
        int key;
        cin >> key;

        double temp = key * A;

        double fractional = temp - (int)temp;

        int index = (int)(m * fractional);

        hashTable[index].push_back(key);
    }

    cout << "\nHash Table:\n";
    for (int i = 0; i < m; i++)
    {
        cout << "Index " << i << ": ";

        for (int j = 0; j < hashTable[i].size(); j++)
        {
            cout << hashTable[i][j] << " -> ";
        }

        cout << "NULL\n";
    }

    return 0;
}