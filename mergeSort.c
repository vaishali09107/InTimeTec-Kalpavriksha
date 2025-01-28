#include<stdio.h>
#include<stdlib.h>

void merge(int *arr,int start,int end)
{
    int mid= (start + end)/2;

    int len1= mid - start + 1;
    int len2= end - mid;

    int *first=(int * )malloc(sizeof(int)*len1);
    int *second=(int *)malloc(sizeof(int)*len2);

    int k=start;
    for(int i=0;i<len1;i++)
    {
        first[i]=arr[k++];
    }
    k=mid + 1;
    for(int i=0;i<len2;i++)
    {
        second[i]=arr[k++];
    }

    int index1=0;
    int index2=0;
    int mainArrayIndex=start;

    while(index1<len1 && index2< len2)
    {
        if(first[index1]<second[index2])
        {
            arr[mainArrayIndex++]=first[index1++];
        }
        else{
            arr[mainArrayIndex++]=second[index2++];
        }
    }

    while(index1 < len1)
    {
        arr[mainArrayIndex++]=first[index1++];
    }
    while(index2 < len2)
    {
        arr[mainArrayIndex++]=second[index2++];
    }

      
}

void mergeSort(int *arr,int start,int end)
{
    if(start>=end)
    {
        return;
    }

    int mid = (start + end)/2;

    mergeSort(arr,start,mid);
    mergeSort(arr,mid+1,end);
    merge(arr,start,end);


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

    mergeSort(arr,0,size-1);
    printf("After sorting:\n");
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);

    }
    printf("\n");

    return 0;

}