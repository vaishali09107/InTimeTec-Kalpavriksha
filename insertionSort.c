#include<stdio.h>
#include<stdlib.h>
void insertionSort(int *arr,int size)
{
    for(int i=1;i<size;i++)
    {
        int temp=arr[i];
        int j=i-1;
        while(j>=0  && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
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

    insertionSort(arr,size);

    printf("After Sorting:\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}