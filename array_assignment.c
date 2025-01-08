#include <stdio.h>
#define MAX_ROWS 10
#define MAX_COLS 101
#define MAX_NAME_LEN 50

int checkVowel(char name[])
{
    char firstChar=name[0];
    return (firstChar=='a'|| firstChar=='e'|| firstChar=='i'|| firstChar=='o'|| firstChar=='u'|| firstChar=='A'|| firstChar=='E'|| firstChar=='I'|| firstChar=='O'|| firstChar=='U');
}
int stringLen(char str[])
{
    int len=0;
    while(str[len]!='\0')
    {
        len++;
    }
    return len;
}
void copyString(char destination[],char source[])
{
    int i=0;
    while(source[i]!='\0')
    {
        destination[i]=source[i];
        i++;
    }
    destination[i]='\0';
}
void longestName(char name[MAX_ROWS][MAX_COLS][MAX_NAME_LEN],int rows,int cols,char longName[])
{
    int maxLen=0,i,j,currentLen;
    for(i=0;i<rows;i++)
    {
        for(j=0;j<cols;j++)
        {
            currentLen=stringLen(name[i][j]);
            if(currentLen>maxLen)
            {
                maxLen=currentLen;
                copyString(longName,name[i][j]);
            }
        }
    }
    
}

int main() {
    int row,col,i,j;
    printf("Enter no. of Rows:");
    scanf("%d\n",&row);
    printf("Enter no. of Columns:");
    scanf("%d",&col);
    if(row<1 || row>10)
    {
        printf("Invalid number of rows.\n");
        return 1;
    }
    if(col<1 || col>10)
    {
        printf("Invalid number of columns.\n");
        return 1;
    }
    char name[MAX_ROWS][MAX_COLS][MAX_NAME_LEN];
    printf("Enter the Names: \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("Name at(%d %d): ",i,j);
            scanf("%s",name[i][j]);
        }
    }
    printf("2D Array : \n");
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            printf("%s ",name[i][j]);
        }
        printf("\n");
    }
    int countVow=0;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(checkVowel(name[i][j]))
            {
                countVow++;
            }
        }
    }
    
    printf("\nNumber of name starting with vowels: %d\n",countVow);
    getchar();
    
    char longName[MAX_NAME_LEN];
    longestName(name,row,col,longName);
    printf("Longest Name: %s\n",longName);
    
    return 0;
}
