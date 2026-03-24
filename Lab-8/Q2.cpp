#include <iostream>
#include <queue>
using namespace std;

int countElements(queue<int> &q)
{
    queue<int> temp;
    int count = 0;

    while (!q.empty())
    {
        temp.push(q.front());
        q.pop();
        count++;
    }

    while (!temp.empty())
    {
        q.push(temp.front());
        temp.pop();
    }

    return count;
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

    cout << "Number of elements: " << countElements(q) << endl;

    return 0;
}