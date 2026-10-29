#include <stdio.h>

void quickSort(int arr[], int low, int high)
{
    int i, j, p, temp;

    if (low < high)
    {
        p = arr[high];
        i = low - 1;

        for (j = low; j < high; j++)
        {
            if (arr[j] < p)
            {
                i++;

                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }


        temp = arr[i + 1];
        arr[i + 1] = arr[high];
        arr[high] = temp;

            quickSort(arr, low, i);
        quickSort(arr, i + 2, high);
    }
}

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements: ");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    quickSort(arr, 0, n - 1);

    printf("Sorted array: ");

    for (i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}
