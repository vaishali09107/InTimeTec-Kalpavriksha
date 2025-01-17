
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void remove_char(char **string,char ch)
{
    int i,j=0;
    for(i=0;(*string)[i]!='\0';i++)
    {
        if((*string)[i]!=ch)
        {
            (*string)[j++]=(*string)[i];
           
        }
    }
    (*string)[j]='\0';
}


int main()
{
    char *string=(char *)malloc(100 * sizeof(char));
    if(string==NULL)
    {
        return 1;
    }
    char character;
    //char result[100];
    
    scanf("%[^\n]",string);
    getchar();
    
    scanf("%c",&character);
    if(strlen(string)==0)
    {
        return 1;
    }
    remove_char(&string,character);
    printf("%s\n",string);

    return 0;
}
