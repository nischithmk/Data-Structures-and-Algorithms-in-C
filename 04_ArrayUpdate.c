#include<stdio.h>

void showArr(int arr[], int size){
for (int i = 0; i < size; i++)
{
    printf("%d ", arr[i]);
    
}
printf("\n");
}

//update
int update(int arr[],int element, int index,int size){

    if(index>=size || index<0) return -1;
    else{
            arr[index] = element;
        } 
        return 1;
    }
    

int main()
{
    int size = 5, index = 0,element=0;
    printf("Enter the index number in  which you want to update the element : ");
    scanf("%d", &index);
    printf("Enter the element which you want to update : ");
    scanf("%d", &element);
    int arr[50] = {10, 20, 30, 40, 50};
    printf("Array before delete operation : ");
    showArr(arr, size);
    int elem = arr[index];
    int res = update(arr, element, index,size);
    if(res>=1){
        printf("Successfully updated\n");
    }
    else{
        printf("Unable to update the element..!\n");
    }
    printf("Array after update operation : ");
    showArr(arr, size);

}
