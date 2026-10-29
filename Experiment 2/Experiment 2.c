#include <stdio.h>

int bin_search(int arr[], int element, int min, int max)
{
    if (min > max)
    {
        return -1;
    }

    int mid = (min + max) / 2;

    if (arr[mid] == element)
    {
        return mid;
    }
    else if (element < arr[mid])
    {
        return bin_search(arr, element, min, mid - 1);
    }
    else
    {
        return bin_search(arr, element, mid + 1, max);
    }
}  

int main()
{
    int n, key, i;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    // Check if array is sorted
    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            printf("Array is Unsorted\n");
            return 0;
        }
    }

    printf("Enter the element to search: ");
    scanf("%d", &key);

 
    int result = bin_search(arr, key, 0, n - 1);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found\n");

    return 0;
}
