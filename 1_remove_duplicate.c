#include <stdio.h>
void removeDuplicate(char *str)
{
    int seen[256]={0};
    int i,j=0;
    for(i=0;str[i]!='\0';i++)
    {
        
        if(seen[str[i]]==0)
        {
            str[j++]=str[i];
            seen[str[i]]=1;
        }
    }
    str[j]='\0';
}
int main()
{
    char string[100];
    
    printf("Enter String: \n");
    scanf("%s",string);
    
    removeDuplicate(string);
    
    printf("string after removinng duplicates: %s\n",string);
    
    
    return 0;
}