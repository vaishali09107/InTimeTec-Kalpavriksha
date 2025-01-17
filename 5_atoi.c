#include<stdio.h>

int checkDigit(char ch)
{
    return ch>='0' && ch<='9';
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
int atoiFunction(char *num)
{
    int isNegative=1;
    int number=0;
    int i=0;
    
    
    
    if(num[i]=='-')
    {
        isNegative=-1;
        i++;
    }
    
    for(;i<length(num);i++)
    {
        if(checkDigit(num[i])==0)
        {
            return 0;
        }
        number=number*10 + (num[i] - '0');
    }
    
    return number * isNegative;
    
   

}

int main()
{
    char num[100];
    printf("Enter the integer string: \n");
    scanf("%s",num);
    
    printf("Integer number is: %d\n",atoiFunction(num));

    return 0;
}