#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[3][3];
    cout << "Enter elements of matrix:\n";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << "Element: " << arr[i][j] << "\t Address: " << &arr[i][j] << endl;
        }
    }
    return 0;
}