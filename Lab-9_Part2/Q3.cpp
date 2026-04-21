#include <iostream>
using namespace std;

int midSquare(int key)
{
    int square = key * key;
    int middle = (square / 10) % 100;

    return middle;
}

int folding(int key)
{
    int sum = 0;

    while (key > 0)
    {
        sum += key % 100; // take last 2 digits
        key /= 100;
    }

    return sum;
}

int main()
{
    int key;

    cout << "Enter key: ";
    cin >> key;

    cout << "Mid-Square Hash: " << midSquare(key) << endl;
    cout << "Folding Hash: " << folding(key) << endl;

    return 0;
}