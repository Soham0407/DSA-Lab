//program to store N integers in a 1D array. 
//Find the maximum and minimum elements.
//​Calculate the average of all elements.
#include <stdio.h>
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max=arr[0];
    int min=arr[0];
    int sum=0,average;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
            max=arr[i];
        if(arr[i]<min)
            min=arr[i];
        sum+=arr[i];
    }
    printf("Maximum element: %d\n",max);
    printf("Minimum element: %d\n",min);
    average=sum/n;
    printf("Average of all elements: %d\n",average);

    int search_element;
    printf("Enter element to search: ");
    scanf("%d",&search_element);
    for(int i=0;i<n;i++)
    {
        if(arr[i]==search_element)
        {
            printf("Element %d found at index %d\n",search_element,i);
            return 0;
        }
    }
}