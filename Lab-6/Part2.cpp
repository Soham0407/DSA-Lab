#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

void push(Node *&top, int value)
{
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = top;
    top = newNode;
}

int pop(Node *&top)
{
    if (top == nullptr)
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    Node *temp = top;
    int poppedValue = top->data;
    top = top->next;
    delete temp;
    return poppedValue;
}

int peek(Node *top)
{
    if (top == nullptr)
    {
        cout << "Stack is empty!" << endl;
        return -1;
    }
    return top->data;
}

bool isEmpty(Node *top)
{
    if (top == nullptr)
    {
        return true;
    }
    return false;
}

int main()
{
    Node *top = nullptr;
    int choice, value;

    do
    {
        cout << "\nMenu: \n";
        cout << "1. Push\n";
        cout << "2. Pop\n";
        cout << "3. Peek\n";
        cout << "4. Check if Stack is Empty\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter value to push: ";
            cin >> value;
            push(top, value);
            cout << value << " pushed onto the stack.\n";
            break;

        case 2:
            value = pop(top);
            if (value != -1)
            {
                cout << "Popped: " << value << endl;
            }
            break;

        case 3:
            value = peek(top);
            if (value != -1)
            {
                cout << "Top of the stack: " << value << endl;
            }
            break;

        case 4:
            if (isEmpty(top))
            {
                cout << "Stack is empty.\n";
            }
            else
            {
                cout << "Stack is not empty.\n";
            }
            break;

        case 5:
            cout << "Exiting\n";
            break;

        default:
            cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}
