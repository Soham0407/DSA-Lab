#include <iostream>
using namespace std;

struct Student  
{
    int rollNo;
    float marks;
};

int main()
{
    // Primitive data types
    int a = 10;
    float x = 5.5;
    char ch = 'A';

    // Non-primitive data types
    int arr[3] = {1, 2, 3};    // Array
    Student s = {1, 89.5};     // Structure

    cout << "For Primitive Data Types" << endl;

    cout << "Integer a = " << a << endl;
    cout << "Address of a = " << &a << endl;
    cout << "Size of a = " << sizeof(a) << endl;

    cout << "Float x = " << x << endl;
    cout << "Address of x = " << &x << endl;
    cout << "Size of x = " << sizeof(x) << endl;

    cout << "Character ch = " << ch << endl;
    cout << "Address of ch = " << (void*)&ch << endl;
    cout << "Size of ch = " << sizeof(ch) << endl;

    
    cout << "For Non-Primitive Data Types" << endl;
    cout << "Array elements:" << endl;
    for(int i = 0; i < 3; i++)
    {
        cout << "arr[" << i << "] = " << arr[i] << "\t Address = " << &arr[i] << endl;
    }
    cout << "Size of array = " << sizeof(arr) << endl;

    cout << "Structure Student:" << endl;
    cout << "Roll No = " << s.rollNo << endl;
    cout << "Marks = " << s.marks << endl;
    cout << "Address of structure = " << &s << endl;
    cout << "Size of structure = " << sizeof(s) << endl;
    return 0;
}
