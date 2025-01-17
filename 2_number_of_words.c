#include <stdio.h>
void removeLeadingSpaces(char *str)
{
    int i,j;
    for(i=0;str[i]==' ';i++)
    {
        
    }
    for(j=0;str[i]!='\0';i++,j++)
    {
        str[j]=str[i];
    }
    str[j]='\0';
    
}
int length(char *str)
{
    int i,len=0;
    for(i=0;str[i]!='\0';i++)
    {
        len++;
    }
    return len;
}

void removeTrailingSpaces(char *str)
{
    int i,j;
    //printf("length: %d\n",length(str));
    for(i=length(str)-1;i>=0;i--)
    {
        if(str[i]==' ' || str[i]=='\n')
        {
            //printf("%d\n",i);
            continue;
        }
        else{
            //printf("%d\n",i);
            break;
        }
    }
    
    str[i + 1]='\0';
    //printf("length: %d\n",length(str));
    
}

void removeExtraSpaces(char *str)
{
    int spaceFlag=0;
    int i=0,j=0;
    while(str[i]!='\0')
    {
        if(str[i]==' ')
        {
            if(!spaceFlag)
            {
                str[j++]=str[i];
                spaceFlag=1;
            }
            
        }
        else{
            str[j++]=str[i];
            spaceFlag=0;
        }
        i++;
    }
    str[j]='\0';
}

int countWords(char *str)
{
    int len=length(str),count=0;
    int inWord=0;
    for(int i=0;i<len;i++)
    {
        if(str[i]!=' ')
        {
            if(!inWord)
            {
                count++;
                inWord=1;
            }
    
        }
        else
        {
            inWord=0;
        }
        
    }
    return count;
}
int main()
{
    char string[100];
    fgets(string,sizeof(string),stdin);
    printf("String is: %s\n",string);
    //printf("length: %d\n",length(string));
    removeLeadingSpaces(string);
    removeTrailingSpaces(string);
    //printf("lString is:%s\n",string);
    //printf("length: %d\n",length(string));
    
    removeExtraSpaces(string);
    
    //printf("lString is:%s\n",string);
    //printf("length: %d\n",length(string)); 
    printf("Number of words: %d\n",countWords(string));
    
    
    
    return 0;
}