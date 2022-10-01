#include<stdio.h>

void showArr(int arr[], int size){
    for (int i = 0; i < size; i++)
    { 
        printf("%d ", arr[i]);

    }
    printf("\n");
}
int linearSearch(int arr[],int size, int element){
    for (int i = 0; i < size; i++)
    {
        if(arr[i]==element){
            return i;
            break;
        }
    }
    return -1;
}

int main(){
    int size = 6,element;
    int arr[50] = {10,20,30,40,50,60};
    printf("Enter the element to search : ");
    scanf("%d", &element);
    showArr(arr, size);
    int res = linearSearch(arr, size, element);
    if(res>=0){
        printf("Element %d is found at position %d ", element, res);
    }
    else{
        printf("Element %d not found..!!!",element);
    }
}
