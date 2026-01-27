#include <bits/stdc++.h>
using namespace std;

/* Display */
void display(int *arr, int size, const string &name)
{
    cout << name << ": ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

/* Insert */
int *insert(int *arr, int &size, int pos, int ele)
{
    if (pos < 1 || pos > size + 1)
    {
        cout << "Invalid position\n";
        return arr;
    }

    size++;
    arr = (int *)realloc(arr, size * sizeof(int));

    for (int i = size - 1; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = ele;
    return arr;
}

/* Delete */
int *Delete(int *arr, int &size, int pos)
{
    if (pos < 1 || pos > size)
    {
        cout << "Invalid position\n";
        return arr;
    }

    for (int i = pos - 1; i < size - 1; i++)
        arr[i] = arr[i + 1];

    size--;
    arr = (int *)realloc(arr, size * sizeof(int));
    return arr;
}

/* Reverse in-place */
void Reverse(int *arr, int size)
{
    for (int i = 0; i < size / 2; i++)
        swap(arr[i], arr[size - i - 1]);
}

/* Reverse using temp */
void ReverseTemp(int *arr, int size)
{
    int *temp = (int *)malloc(size * sizeof(int));
    for (int i = 0; i < size; i++)
        temp[i] = arr[size - i - 1];

    memcpy(arr, temp, size * sizeof(int));
    free(temp);
}

/* Sum */
int sum(int *arr, int size)
{
    int s = 0;
    for (int i = 0; i < size; i++)
        s += arr[i];
    return s;
}

/* Recursive sum */
int sumRec(int *arr, int size)
{
    if (size == 0)
        return 0;
    return arr[size - 1] + sumRec(arr, size - 1);
}

/* Search */
int Search(int *arr, int size, int key)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == key)
            return i + 1;
    return -1;
}

/* Copy to MainArray */
void copyToMain(int *src, int srcSize, int *dest, int &destSize, int start, int end)
{
    if (start < 1 || end > srcSize || start > end)
    {
        cout << "Invalid range\n";
        return;
    }

    for (int i = start - 1; i < end; i++)
        dest[destSize++] = src[i];
}

/* Merge Descending */
void mergeDesc(int *a, int *b, int *c, int size)
{
    sort(a, a + size);
    sort(b, b + size);

    int i = size - 1, j = size - 1, k = 0;

    while (i >= 0 && j >= 0)
        c[k++] = (a[i] > b[j]) ? a[i--] : b[j--];

    while (i >= 0)
        c[k++] = a[i--];
    while (j >= 0)
        c[k++] = b[j--];
}

/* Separate */
void Separate(int *arr, int size)
{
    if (size == 0)
    {
        cout << "MainArray is empty\n";
        return;
    }

    cout << "Even: ";
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 == 0)
            cout << arr[i] << " ";

    cout << "\nOdd: ";
    for (int i = 0; i < size; i++)
        if (arr[i] % 2 != 0)
            cout << arr[i] << " ";

    cout << "\nPositive: ";
    for (int i = 0; i < size; i++)
        if (arr[i] >= 0)
            cout << arr[i] << " ";

    cout << "\nNegative: ";
    for (int i = 0; i < size; i++)
        if (arr[i] < 0)
            cout << arr[i] << " ";

    cout << endl;
}

int main()
{
    int size1 = 10, size2 = 10, mainSize = 0;

    int *SubArray1 = (int *)malloc(10 * sizeof(int));
    int *SubArray2 = (int *)malloc(10 * sizeof(int));
    int *MainArray = (int *)malloc(20 * sizeof(int));

    cout << "Enter 10 elements for SubArray1:\n";
    for (int i = 0; i < 10; i++)
        cin >> SubArray1[i];

    cout << "Enter 10 elements for SubArray2:\n";
    for (int i = 0; i < 10; i++)
        cin >> SubArray2[i];

    int choice;
    cout << "\n1.Insert\n2.Delete\n3.Reverse(temp)\n4.Reverse(in-place)"
         << "\n5.Copy to MainArray\n6.Merge Descending\n7.Sum\n8.Sum Rec"
         << "\n9.Search\n10.Separate\n0.Exit\nChoice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        int pos, ele;
        cout << "Position: ";
        cin >> pos;
        cout << "Element: ";
        cin >> ele;
        SubArray1 = insert(SubArray1, size1, pos, ele);
        display(SubArray1, size1, "SubArray1");
        break;
    }

    case 2:
    {
        int pos;
        cout << "Position: ";
        cin >> pos;
        SubArray1 = Delete(SubArray1, size1, pos);
        display(SubArray1, size1, "SubArray1");
        break;
    }

    case 3:
        ReverseTemp(SubArray1, size1);
        display(SubArray1, size1, "SubArray1");
        break;

    case 4:
        Reverse(SubArray1, size1);
        display(SubArray1, size1, "SubArray1");
        break;

    case 5:
    {
        int s, e;
        cout << "Start position: ";
        cin >> s;
        cout << "End position: ";
        cin >> e;
        copyToMain(SubArray1, size1, MainArray, mainSize, s, e);
        display(MainArray, mainSize, "MainArray");
        break;
    }

    case 6:
        mergeDesc(SubArray1, SubArray2, MainArray, 10);
        mainSize = 20;
        display(MainArray, mainSize, "Merged(MainArray)");
        break;

    case 7:
        cout << "Sum = " << sum(SubArray1, size1) << endl;
        break;

    case 8:
        cout << "Sum (Rec) = " << sumRec(SubArray1, size1) << endl;
        break;

    case 9:
    {
        int key;
        cout << "Search element: ";
        cin >> key;
        cout << "Position: " << Search(SubArray1, size1, key) << endl;
        break;
    }

    case 10:
        Separate(MainArray, mainSize);
        break;
    }

    free(SubArray1);
    free(SubArray2);
    free(MainArray);
    return 0;
}