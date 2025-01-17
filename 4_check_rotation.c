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
void concatenate(char **string1,char *string2)
{
    int len1=length(*string1);
    int len2=length(string2),i;
    for(i=0;i<len2;i++)
    {
        (*string1)[len1+ i]=string2[i];
    }
    (*string1)[len1+len2]='\0';
    
    
}


int substring(char *string1,char *string2)
{
    int str1Len=length(string1),str2Len=length(string2);
    int found=0;
    char *ptr1=string1;
    char *ptr2=string2;
  
    if((str1Len/2)!=str2Len)
    {
        return 0;
    }
    for(int j=0;j<str1Len;j++)
    {
        if(*ptr1==*ptr2)
        {
            ptr2++;
            found++;
            if(found==str2Len)
            {
                return 1;
            }
        }
        else
        {
             ptr1-=found;
             ptr2=string2;
             found=0;
        }
        ptr1++;

    }
    return 0;
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
    printf("Enter string1: \n");
    fgets(string1,100,stdin);
    for(char *ptr=string1;*ptr!='\0';ptr++)
    {
        if(*ptr=='\n')
        {
            *ptr='\0';
            break;
        }
    }
    printf("Enter string2: \n");
    fgets(string2,100,stdin);
    for(char *ptr=string2;*ptr!='\0';ptr++)
    {
        if(*ptr=='\n')
        {
            *ptr='\0';
            break;
        }
    }
    
    //printf("String1: %s\n",string1);
    //printf("String2: %s\n",string2);
    
    if(length(string1)>length(string2) || length(string1)<length(string2))
    {
        printf("False\n");
        return 0;
    }
    //bool ans=checkRotation(string1,string2);
    //printf("Ans: %s\n",ans);
    concatenate(&string1,string1);
    //printf("%s\n",string1);
    
    if(substring(string1,string2)==1)
    {
        printf("True\n");
    }
    else
    {
        printf("False\n");
    }
    
    //printf("True",substring(string1,string2));

    return 0;
}