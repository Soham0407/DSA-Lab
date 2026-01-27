#include <bits/stdc++.h>
using namespace std;

int main()
{
    int m, n;
    cout << "Enter the No. of Rows and Columns:";
    cin >> m >> n;
    int arr[m][n];
    cout << "Enter array elements according to row major order \n";
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}