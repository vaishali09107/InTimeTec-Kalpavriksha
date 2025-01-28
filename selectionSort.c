#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int temp= *a;
    *a= *b;
    *b = temp;
}

void selectionSort(int *arr,int size)
{
    for(int i=0;i<size-1;i++)
    {
        int min=i;
        for(int j=i+1;j<size;j++)
        {
            if(arr[j]<arr[min])
            {
                min=j;
            }
        }
        if(min !=i)
        {
            swap(&arr[i],&arr[min]);
        }

    }
}

int main()
{
    int size;
    printf("Enter the size of array:\n");
    scanf("%d",&size);
    int *arr=(int *)malloc(sizeof(int)*size);
    printf("Enter the elements: \n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }

    selectionSort(arr,size);
    printf("After sorting:\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);

    }
    printf("\n");
}