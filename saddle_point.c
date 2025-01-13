#include <stdio.h>
int minInRow(int *ptr,int row,int col,int rowIndex)
{
    int j,min=*(ptr + rowIndex * col);
    for(j=0;j<col;j++)
    {
        if(*(ptr + rowIndex * col + j)<min){
            min=*(ptr + rowIndex * col + j);
        }
    }
    return min;
}
int maxInColumn(int *ptr,int row,int col,int colIndex)
{
    int i,max=*(ptr + colIndex);
    for(i=0;i<row;i++)
    {
        if(*(ptr + i *col + colIndex )> max)
        {
            max=*(ptr + i * col + colIndex );
        }
    }
    return max;
}

int solution(int arr1[],int arr2[],int row,int col,int *array)
{
    int i,j;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if (*(array + i * col + j)==arr1[i]  )
            {
                if(*(array + i * col + j)==arr2[j])
                {
                    printf("Ans: %d\n",*(array + i * col + j));
                    return 1;
                }
            }
        }
    }
    printf("%d",-1);
    return 0;
}
int main()
{
    int row,col,i,j;
    printf("Enter number of rows: \n");
    scanf("%d",&row);
    printf("Enter number of col: \n");
    scanf("%d",&col);
    int arr[row][col];
    int rowMinArray[row];
    int columnMaxArray[col];
    
    int *ptr=(int *)arr;
    printf("Enter the array elements: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",(ptr + i * col + j));
        }
    }
    printf("printing array: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",*(ptr + i * col + j));
        }
        printf("\n");
    }
    for(i=0;i<row;i++)
    {
        rowMinArray[i]=minInRow(ptr,row,col,i);
    }
   
    
    for(i=0;i<col;i++)
    {
        columnMaxArray[i]=maxInColumn(ptr,row,col,i);
    }
   
    solution(rowMinArray,columnMaxArray,row,col,ptr);
    return 0;
}