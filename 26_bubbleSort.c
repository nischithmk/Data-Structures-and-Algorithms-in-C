#include <stdio.h>
#include <stdlib.h>

int *bubbleSort(int *arr, int n)
{
    int temp;
    int isSorted = 0;
    for (int i = 0; i < n; i++)
    {
        // make sorted as true
        isSorted = 1;
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // if it comes inside if loop then arr is not sorted so isSorted false
                isSorted = 0;
            }
        }
        // check if array is sorted after each pass
        //  if array is sorted after any pass stop the comparison
        if (isSorted)
        {
            return arr;
        }
    }
}

void main()
{
    int arr[] = {9, 1, 10, 6, 9, 7, 15, 2, 3};
    int n = 9;
    printf("Array before sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
    int *sortedArr = bubbleSort(arr, n);
    printf("\nArray after sorting\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", sortedArr[i]);
    }
}