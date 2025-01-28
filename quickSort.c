#include<stdio.h>
#include<stdlib.h>
void swap(int *a,int *b)
{
    int temp= *a;
    *a= *b;
    *b = temp;
}

int partitionArray(int *array,int lowerBound,int upperBound)
{
    int pivot;
    pivot=array[lowerBound];
    int start=lowerBound;
    int end=upperBound;
    while(start<end)
    {
        while(array[start]<=pivot)
        {
            start++;
        }
        while(array[end]>pivot)
        {
            end--;
        }
        if(start < end)
        {
            swap(&array[start],&array[end]);
        }
    }
    swap(&array[lowerBound],&array[end]);
    return end;

}

void quickSort(int *arr,int lowerBound,int upperBound)
{
    if(lowerBound<upperBound)
    {
        int location=partitionArray(arr,lowerBound,upperBound);
        quickSort(arr,lowerBound,location-1);
        quickSort(arr,location+1,upperBound);
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

    quickSort(arr,0,size-1);
    printf("After sorting:\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);

    }
    printf("\n");
}