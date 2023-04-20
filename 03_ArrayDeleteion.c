#include<stdio.h>


void showArr(int arr[], int size){
for (int i = 0; i < size; i++)
{
    printf("%d ", arr[i]);
    
}
printf("\n");
}


int deleteInMiddle(int arr[],int size, int index){

    if(index>=size || index<0) return -1;
    else{
        for (int i = index; i < size; i++){
            arr[i] = arr[i + 1];
        } 
        return 1;
    }
    
}

int main()
{
    int size = 5, index = 0;
    printf("Enter the index number from which you want to remove the element : ");
    scanf("%d", &index);
    int arr[50] = {10, 20, 30, 40, 50};
    printf("Array before delete operation : ");
    showArr(arr, size);
    int elem = arr[index];
    int res = deleteInMiddle(arr, size, index);
    if(res>=1){
        printf("Successfully deleted %d from %dth position\n", elem, index);
        size -= 1;
    }
    else{
        printf("Unable to delete the element..!\n");
    }
    printf("Array after delete operation : ");
    showArr(arr, size);

}
