#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cout << "Enter size of array a: ";
    cin >> n;

    int a[n];
    cout << "Enter elements of array a: ";
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << "Enter size of array b: ";
    cin >> m;

    int b[m];
    cout << "Enter elements of array b: ";
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }

    unordered_set<int> setA;
    unordered_set<int> result;

    for (int i = 0; i < n; i++)
    {
        setA.insert(a[i]);
    }

    for (int i = 0; i < m; i++)
    {
        if (setA.count(b[i]))
        {
            result.insert(b[i]);
        }
    }

    cout << "Intersection: ";
    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}