#include <bits/stdc++.h>
#include <stack>
#include <queue>
using namespace std;

queue<int> reverseQueue(queue<int> q)
{
    if (q.empty())
        return q;
    int x = q.front();
    q.pop();
    q = reverseQueue(q);
    q.push(x);
    return q;
}

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
    q = reverseQueue(q);
    cout << "Elements in the reversed queue are: ";
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    cout << endl;
}