#include <bits/stdc++.h>
#include <stack>
using namespace std;

int evaluatePostfix(string postfix)
{
    stack<int> s;

    for (int i = 0; i < postfix.length(); i++)
    {
        char ch = postfix[i];

        if (ch >= '0' && ch <= '9')
        {
            s.push(ch - '0');
        }

        else
        {
            int val2 = s.top();
            s.pop();
            int val1 = s.top();
            s.pop();

            switch (ch)
            {
            case '+':
                s.push(val1 + val2);
                break;
            case '-':
                s.push(val1 - val2);
                break;
            case '*':
                s.push(val1 * val2);
                break;
            case '/':
                s.push(val1 / val2);
                break;
            case '^':
                s.push(pow(val1, val2));
                break;
            case '%':
                s.push(val1 % val2);
                break;
            }
        }
    }

    return s.top();
}

int main()
{
    string postfix;

    cout << "Enter Postfix Expression: ";
    cin >> postfix;

    cout << "Result: " << evaluatePostfix(postfix);

    return 0;
}
