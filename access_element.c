#include <stdio.h>

int main()
{
    int array[3][4]={1,3,5,7,9,2,4,6,8,0,1,9},i,j;
    //accessing 2d array elemets
    //1.using indexing
    printf("printing 2d array through indexing: \n");
    for (i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",array[i][j]);
        }
        printf("\n");
    }
    
    //2.using pointer arithmetic
    int *ptr=(int *)array;
    printf("printing 2d array through pointer arithmetic: \n");
    for (i=0;i<12;i++)
    {
        if(i%4==0 && i!=0)
        {
            printf("\n");
        }
        printf("%d ",*(ptr + i));
      
    }
    printf("\n");
    
    //3.pointer to a row
    printf("printing 2d array through pointer to a row: \n");
    for (i=0;i<3;i++)
    {
        int *ptr=array[i];
        for(j=0;j<4;j++)
        {
            printf("%d ",ptr[j]);
        }
        printf("\n");
    }
    printf("printing 2d array through *(array + i): \n");
    //4.uisng*(array + i)
    for (i=0;i<3;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d ",*(*(array + i) + j));
        }
        printf("\n");
    }
    

    return 0;
}