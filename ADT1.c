#include<stdio.h>
#include<stdlib.h>

struct myArr
{
    int tot_size;
    int used_size;
    int *ptr;
};

void CreateArr(struct myArr * arr,int tSize, int uSize){

    arr->tot_size = tSize;
    arr->used_size = uSize;
    arr->ptr = (int *)malloc(tSize * sizeof(int));
}

int main()
{
    struct myArr marks;
    CreateArr(&marks, 10, 5);
    printf(&marks);
}
