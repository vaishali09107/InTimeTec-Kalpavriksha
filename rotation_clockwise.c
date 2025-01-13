#include <stdio.h>
#include<stdlib.h>
void swap(int *x,int *y)
{
    int temp;
    temp= *x;
    *x=*y;
    *y=temp;
}

void transpose(int **matrix,int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=i+1;j<size;j++)
        {
            swap(&matrix[i][j],&matrix[j][i]);
        }
        
    }
}

void rotate(int **matrix,int size)
{
    int i,j;
    for(i=0;i<size;i++)
    {
        for(j=0;j<size/2;j++)
        {
            swap(&matrix[i][j],&matrix[i][size-j-1]);
        }
    }
}
int main()
{
    int size,i,j;
    printf("enter thr size of array: \n");
    scanf("%d",&size);
    
    int **matrix=(int **)malloc(size * sizeof(int *));
    
    for(i=0;i<size;i++)
    {
        matrix[i]=(int *)malloc(size * sizeof(int));
    }
    
    printf("Enter the array elements: \n");
    
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    transpose(matrix,size);
   
    rotate(matrix,size);
    printf("After rotating clockwise: \n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}