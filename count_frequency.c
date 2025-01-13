#include <stdio.h>
#include<stdlib.h>

int countFrequency(int *arr,int row,int col,int word)
{
    int i,j,count=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if((*(arr + i * col + j)) == word)
            {
                count=count+1;
            }
        }
    }
    return count;
}


int main()
{
    int row,col,i,j;
    printf("Enter no of rows: \n");
    scanf("%d",&row);
    printf("Enter no of cols: \n");
    scanf("%d",&col);
    int *arr=(int *)malloc(row * col * sizeof(int));
     if (arr == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }
    
    printf("ENter array elements: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            scanf("%d",(arr + i * col + j));
        }
        
    }
    printf("printinf array elements: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%d ",*(arr + i * col + j));
        }
        printf("\n");
        
    }
    int check[100]={0};
    //printf("Count frew: %d",countFrequency(arr,row,col,6));
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(check[*(arr + i * col + j)]==0)
            {
                printf("%d -> %d times\n",*(arr + i * col + j),countFrequency(arr,row,col,*(arr + i * col + j)));
                check[*(arr + i * col + j)]+=1;
            }
        }
    }
    free(arr);
    return 0;
}