#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str;

    cout << "Enter a string: ";
    cin >> str;

    int n = str.length();

    char *stackArr = new char[n];
    int top = -1;

    for (int i = 0; i < n; i++)
    {
        stackArr[++top] = str[i];
    }

    for (int i = 0; i < n; i++)
    {
        str[i] = stackArr[top--];
    }

    cout << "Reversed string: " << str << endl;

    delete[] stackArr;
    return 0;
}
