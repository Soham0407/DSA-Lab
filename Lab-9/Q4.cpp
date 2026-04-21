#include <iostream>
#include <unordered_map>
using namespace std;

int countPairs(int arr[], int n, int target)
{
    unordered_map<int, int> freq;
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        int complement = target - arr[i];

        if (freq.find(complement) != freq.end())
        {
            count += freq[complement];
        }

        freq[arr[i]]++;
    }

    return count;
}

int main()
{
    int n, target;

    cout << "Enter number of elements: ";
    cin >> n;

    int arr[n];

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter target: ";
    cin >> target;

    int result = countPairs(arr, n, target);

    cout << "Number of pairs: " << result << endl;

    return 0;
}