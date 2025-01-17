
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

int checkAnagram(char *string1,char *string2)
{
    int count=length(string1);
    
    int i,j;
    
    for(i=0;i<length(string1);i++)
    {
        for(j=0;j<length(string2);j++)
        {
            if(string1[i]==string2[j])
            {
                count--;
            }
        }
    }
    if(count==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{
    char *string1=(char *)malloc(100 * sizeof(char));
    char *string2=(char *)malloc(100 * sizeof(char));
    
    if(string1==NULL)
    {
        return 1;
    }
    if(string2==NULL)
    {
        return 1;
    }
    
    fgets(string1,100,stdin);
    for(int i=0;string1[i]!='\0';i++)
    {
        if(string1[i]=='\n')
        {
            string1[i]='\0';
            break;
        }
    }
    fgets(string2,100,stdin);
    for(int i=0;string2[i]!='\0';i++)
    {
        if(string2[i]=='\n')
        {
            string2[i]='\0';
            break;
        }
    }
    
    int len1=length(string1);
    int len2=length(string2);
    
    if(len1!=len2)
    {
        printf("False\n");
        return 0;
    }
    if(string1[0]=='\0' || string2[0]=='\0')
    {
        printf("False\n");
        return 0;
    }
    if(checkAnagram(string1,string2))
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    //printf("Is amagaram : %d",checkAnagram(string1,string2));
 
    

    return 0;
}