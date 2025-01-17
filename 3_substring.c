#include <stdio.h>
#include<stdlib.h>
int length(char *string)
{
    int i=0,len=0;
    while(string[i]!='\0')
    {
        len++;
        i++;
    }
    return len;
}
int substring(char *string,char *substr)
{
    int stringLen=length(string);
    int substringLen=length(substr);
    int i=0,j=0,found=0,startIndex;
    
    while(j<stringLen)
    {
        if(substr[i]==string[j])
        {
            if(found==0)
            {
                startIndex=j;
            }
            i++;
            found++;
            if(found==substringLen)
            {
                
                return startIndex;
            }
        }
        else
        {
            j=j-found;
            i=0;
            found=0;
        }
        j++;
    }
    return -1;
}
int main()
{
    char *string=(char *)malloc(100 * sizeof(char));
    char *substr=(char *)malloc(100 * sizeof(char));
    if(string == NULL)
    {
        printf("Memory allocation failed for string\n");
        return 1;
    }
    if(substr==NULL)
    {
        printf("Memory allocation failed for substring\n");
        return 1;
    }
    printf("Enter string: \n");
    fgets(string,100,stdin);
    for(int i=0;string[i]!='\0';i++)
    {
        if(string[i]=='\n')
        {
            string[i]='\0';
            break;
        }
    }
    printf("ENter substring to check: \n");
    fgets(substr,100,stdin);
    for(int i=0;substr[i]!='\0';i++)
    {
        if(substr[i]=='\n')
        {
            substr[i]='\0';
            break;
        }
    }
    if(string[0]=='\0' || string[0]=='\n')
    {
        printf("Empty\n");
        return 1;
    }
    if(substr[0]=='\0' || substr[0]=='\n')
    {
        printf("Empty\n");
        return 1;
    }
    
    printf("String is : %s\nSubstring is: %s\n",string,substr);
    
    //printf("Length of string: %d\nLength of substring: %d\n",length(string),length(substr));
    
    //printf("Is substring: %d\n",substring(string,substr));

    if(substring(string,substr)!=-1)
    {
        printf("%d\n",substring(string,substr));
    }
    else
    {
        printf("%d\n",-1);
    }

    return 0;
}