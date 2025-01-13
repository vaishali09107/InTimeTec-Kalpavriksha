#include <stdio.h>
int checkInarray(int arr[],int target,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        if(arr[i]==target)
        {
            return 1;
        }
    }
    return 0;
    
}

int main()
{
    int size,i,j,dindex=0;
    int sum=0;
    
    printf("ENter size: \n");
    scanf("%d",&size);
    int diagonal[size*size];
    int matrix[size][size];
    for (i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
    }
    printf("2d Matrix: \n");
    for(i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            printf("%d ",matrix[i][j]);
        }
        printf("\n");
    }
   
    for (i=0;i<size;i++)
    {
        for(j=0;j<size;j++)
        {
            if (i==j)
            {
                if (!checkInarray(diagonal,matrix[i][j],dindex))
                {
                    diagonal[dindex]=matrix[i][j];
                    dindex++;
                }
                
            }
            if((i+j)==size-1)
            {
                if (!checkInarray(diagonal,matrix[i][j],dindex))
                {
                    diagonal[dindex]=matrix[i][j];
                    dindex++;
                }
            }
        }
    }
  
    for (i=0;i<dindex;i++)
    {
        sum+=diagonal[i];
    }
    printf("Sum : %d\n",sum);
    
    
    return 0;
}