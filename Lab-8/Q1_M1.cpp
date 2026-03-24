#include <bits/stdc++.h>
#include <stack>
#include <queue>
using namespace std;
int main()
{
    queue<int> q;
    cout << "Enter the elements of the queue (enter -1 to stop): ";
    while (true)
    {
        int x;
        cin >> x;
        if (x == -1)
            break;
        q.push(x);
    }
    stack<int> s;
    while (!q.empty())
    {
        s.push(q.front());
        q.pop();
    }
    cout << "Elements in the stack are: ";
    while (!s.empty())
    {
        q.push(s.top());
        s.pop();
    }
    cout << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
}