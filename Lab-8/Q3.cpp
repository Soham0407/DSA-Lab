#include <iostream>
#include <queue>
using namespace std;

void FindMinAndMax(queue<int> &q)
{
    queue<int> temp;
    int max = q.front();
    int min = q.front();

    while (!q.empty())
    {
        temp.push(q.front());
        if (q.front() > max)
            max = q.front();
        if (q.front() < min)
            min = q.front();
        q.pop();
    }

    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }
    cout << "Maximum element: " << max << endl;
    cout << "Minimum element: " << min << endl;
}

int main()
{
    queue<int> q;
    int x;
    cout << "Enter elements:(-1 to exit) ";
    while (true)
    {
        cin >> x;
        if (x == -1)
            break;
        q.push(x);
    }
    FindMinAndMax(q);
    return 0;
}