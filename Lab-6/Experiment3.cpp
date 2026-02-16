#include <bits/stdc++.h>
#include <stack>
using namespace std;

bool isBalanced(string expr)
{
    stack<char> s;

    for (int i = 0; i < expr.length(); i++)
    {
        char ch = expr[i];

        if (ch == '(' || ch == '{' || ch == '[')
        {
            s.push(ch);
        }

        else if (ch == ')' || ch == '}' || ch == ']')
        {
            if (s.empty())
                return false;

            char top = s.top();
            s.pop();

            if ((ch == ')' && top != '(') || (ch == '}' && top != '{') || (ch == ']' && top != '['))
            {
                return false;
            }
        }
    }

    // If stack is empty, brackets are balanced
    return s.empty();
}

int main()
{
    string expression;

    cout << "Enter expression: ";
    getline(cin, expression);

    if (isBalanced(expression))
        cout << "Balanced" << endl;
    else
        cout << "Not Balanced" << endl;

    return 0;
}
