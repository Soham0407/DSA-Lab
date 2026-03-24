#include <bits/stdc++.h>
#include <string>
using namespace std;

#define MAX 100

int main() {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    char arr[MAX];
    int front = -1, rear = -1;

    for (int i = 0; i < str.length(); i++) {
        if (rear == MAX - 1) {
            cout << "Deque Overflow\n";
            return 0;
        }
        if (front == -1)
            front = 0;
        arr[++rear] = str[i];
    }

    bool isPalindrome = true;

    while (front < rear) {
        if (arr[front] != arr[rear]) {
            isPalindrome = false;
            break;
        }
        front++;
        rear--;
    }

    if (isPalindrome)
        cout << "Palindrome" << endl;
    else
        cout << "Not Palindrome" << endl;

    return 0;
}