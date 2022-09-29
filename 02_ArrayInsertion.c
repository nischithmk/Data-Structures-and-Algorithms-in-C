#include<stdio.h>

void showArr(int arr[], int size){
for (int i = 0; i < size; i++)
{
    printf("%d ", arr[i]);
    
}
printf("\n");
}


int insertInMiddle(int arr[],int size,int capacity,int index,int element){
if(index>=capacity){
    return -1;
}
else{
for (int i = size-1; i >=index; i--)
{  
    arr[i + 1] = arr[i];
}
arr[index] = element;
}
return 1;
}

int main()
{
    int size = 5,index,element;
    printf("Enter the poisition in which you want to insert : ");
    scanf("%d", &index);
    printf("Enter the element you want to insert in %d th position : ",index);
    scanf("%d",&element);
    int arr[50] = {4, 5, 6, 88, 20};
    showArr(arr, size);
    int ins = insertInMiddle(arr, size, 100, index,element);
    if(ins>=1){
        printf("Element inserted Successfully\n");
        size += 1;
        showArr(arr, size);

    }
    else{
        printf("Element not inserted\n");
    }

}
