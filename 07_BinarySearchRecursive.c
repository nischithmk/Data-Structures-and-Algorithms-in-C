#include<stdio.h>

void showArr(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

    // code for search in ascending order array elements
int binarSearchRecursive(int arr[],int low,int high, int element){

    // int count = 0;
    while(low<=high){
        // count += 1;
        int mid = (low + high) / 2;
        if(element==arr[mid]){
            // printf("%d", count);
            return mid;
        }
        else if(element>arr[mid])
            return binarSearchRecursive(arr, mid + 1, high, element);
        else
            return binarSearchRecursive(arr, low, mid - 1, element);
    }
    return -1;
}

int main(){
    int element=0;
    int arr[] = {10,20,30,40,50,60};
    int size = sizeof(arr)/sizeof(int);

    // code for search in ascending order array elements
    printf("Enter the element to search : ");
    scanf("%d", &element);
    printf("Elements of array : ");
    showArr(arr, size);

    int res = binarSearchRecursive(arr, 0, size-1, element);
    if(res>=0){
        printf("Element  %d found at position %d\n", arr[res],res);
    }
    else{
        printf("Element not found..!\n");
    }

}
