#include<stdio.h>

void showArr(int arr[], int size){
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

    // code for search in ascending order array elements
int binarSearchAsc(int arr[],int size, int element){
    int low=0, high=size-1, mid=0;
    while(low<=high){
        mid = (low + high) / 2;

        if(element==arr[mid])
            return mid;
        else if(element>arr[mid])
            low = mid+1;
        else
            high = mid-1;
    }
    return -1;
}

    // code for search in descending order array elements
int binarSearchDesc(int arr[],int size,int element){
    int low = 0, high = size - 1,mid=0;
    while(low<=high){
        mid = low + (high - low) / 2;
        if(arr[mid]==element)
            return mid;
        else if(element>arr[mid])
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}

int main(){
    int element1=0,element2=0;
    int arrAsc[] = {10,20,30,40,50,60};
    int arrDesc[] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};
    int size1 = sizeof(arrAsc)/sizeof(int);
    int size2 = sizeof(arrDesc)/sizeof(int);
    // code for search in ascending order array elements
    printf("Enter the element to search in ascending order array: ");
    scanf("%d", &element1);
    printf("Elements of ascending array : ");
    showArr(arrAsc, size1);

    int res = binarSearchAsc(arrAsc, size1, element1);
    if(res>=0){
        printf("Element  %d found at position %d\n", arrAsc[res],res);
    }
    else{
        printf("Element not found..!\n");
    }

    // code for search in descending order array elements
    printf("Enter the element to search in descending order array: ");
    scanf("%d", &element2);
    printf("Elements of descending array : ");
    showArr(arrDesc, size2);

    int res2 = binarSearchDesc(arrDesc, size2, element2);
    if(res2>=0){
        printf("Element  %d found at position %d\n", arrDesc[res2],res2);
    }
    else{
        printf("Element not found..!\n");
    }

}
