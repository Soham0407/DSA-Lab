#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    int tree[n];

    cout << "Enter elements (use -1 for empty nodes):\n";
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
    }

    cout << "\nBinary Tree (Array Representation):\n";
    for (int i = 0; i < n; i++)
    {
        if (tree[i] != -1)
        {
            cout << "Node: " << tree[i];

            if (2 * i + 1 < n && tree[2 * i + 1] != -1)
                cout << ", Left Child: " << tree[2 * i + 1];

            if (2 * i + 2 < n && tree[2 * i + 2] != -1)
                cout << ", Right Child: " << tree[2 * i + 2];

            cout << endl;
        }
    }

    return 0;
}