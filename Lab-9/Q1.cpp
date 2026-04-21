#include <iostream>
#include <unordered_set>
using namespace std;

bool isSubset(int a[], int m, int b[], int n)
{
    unordered_set<int> s;

    for (int i = 0; i < m; i++)
    {
        s.insert(a[i]);
    }

    // Check elements of b
    for (int i = 0; i < n; i++)
    {
        if (s.count(b[i]) == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int m, n;

    cout << "Enter size of array a: ";
    cin >> m;

    int a[m];
    cout << "Enter elements of array a: ";
    for (int i = 0; i < m; i++)
    {
        cin >> a[i];
    }

    cout << "Enter size of array b: ";
    cin >> n;

    int b[n];
    cout << "Enter elements of array b: ";
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    if (isSubset(a, m, b, n))
    {
        cout << "true\n";
    }
    else
    {
        cout << "false\n";
    }

    return 0;
}