#include <bits/stdc++.h>
using namespace std;

int top = -1;
int size;
int *stackArr;

bool isEmpty()
{
    return (top == -1);
}

bool isFull()
{
    return (top == size - 1);
}

void push(int value)
{
    if (isFull())
    {
        cout << "Stack Overflow " << value << endl;
        return;
    }
    stackArr[++top] = value;
    cout << value << " pushed into stack.\n";
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack Empty.\n";
        return -1;
    }
    return stackArr[top--];
}

int peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty.\n";
        return -1;
    }
    return stackArr[top];
}

int main()
{
    int choice, value;

    cout << "Enter stack size: ";
    cin >> size;

    stackArr = new int[size];

    do
    {
        cout << "\n----- STACK MENU -----\n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Empty\n";
        cout << "5. Check if Full\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(value);
            break;

        case 2:
            value = pop();
            if (value != -1)
                cout << "Popped element: " << value << endl;
            break;

        case 3:
            value = peek();
            if (value != -1)
                cout << "Top element: " << value << endl;
            break;

        case 4:
            if (isEmpty())
                cout << "Stack is Empty.\n";
            else
                cout << "Stack is NOT Empty.\n";
            break;

        case 5:
            if (isFull())
                cout << "Stack is Full.\n";
            else
                cout << "Stack is NOT Full.\n";
            break;

        case 6:
            cout << "Exiting program...\n";
            break;

        default:
            cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 6);

    delete[] stackArr;
    return 0;
}
