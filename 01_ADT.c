#include<stdio.h>
#include<stdlib.h>

struct myArr
{
    int tot_size;
    int used_size;
    int *ptr;
};

void createArr(struct myArr * arr){
    
    int tSize, uSize;
    printf("Enter size of the array to create : ");
    scanf("%d", &tSize);
    printf("How many elements you want insert? : ");
    scanf("%d", &uSize);

    arr->tot_size = tSize;
    arr->used_size = uSize;
    arr->ptr = (int *)malloc(tSize * sizeof(int));
}

void showArr(struct myArr * arr){
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("%d\n", arr->ptr[i]);
    }
}

void setArr(struct myArr * arr){
    int n;
    for (int i = 0; i < arr->used_size; i++)
    {
        printf("Enter the value for %dth position : ",i);
        scanf("%d", &n);
        arr->ptr[i] = n;
    } 
}

int sumArr(struct myArr * arr){
    int sum_arr = 0;
    for (int i = 0; i < arr->used_size; i++)
    {
        sum_arr = sum_arr + arr->ptr[i];
    }
    return sum_arr;
}

int main()
{
    struct myArr marks;
    createArr(&marks);
    printf("SetArr function execution started\n");
    setArr(&marks);
    printf("ShowArr function execution started\n");
    showArr(&marks);
    printf("The sum of array is %d", sumArr(&marks));
    return 0;
}
