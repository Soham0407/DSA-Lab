#include <iostream>
#include <unordered_map>
using namespace std;

int maxDistance(int arr[], int n)
{
    unordered_map<int, int> firstIndex;
    int maxDist = 0;

    for (int i = 0; i < n; i++)
    {
        // If element seen first time, store index
        if (firstIndex.find(arr[i]) == firstIndex.end())
        {
            firstIndex[arr[i]] = i;
        }
        else
        {
            // Calculate distance
            int dist = i - firstIndex[arr[i]];
            if (dist > maxDist)
            {
                maxDist = dist;
            }
        }
    }

    return maxDist;
}

int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "Maximum distance: " << maxDistance(arr, n) << endl;

    return 0;
}