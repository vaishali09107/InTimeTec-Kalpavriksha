#include <stdio.h>
 
int length(char str[])
{
    int len=0,i;
    for(i=0;str[i]!='\0';i++)
    {
        len+=1;
    }
    return len;
}

int checkDigit(char ch)
{
    //int temp = ch -'0';
    if (ch>='0' && ch<='9')
    {
        return 1;
    }
    return 0;
}
int countSeparator(char str[])
{
    int i,count=0;
    for(i=0;i<length(str);i++)
    {
        if(str[i]=='.')
        {
            count+=1;
        }
    }
    if(count==3)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int validateCharacters(char str[])
{
    int i,countValid=0;
    for(i=0;i<length(str);i++)
    {
        if(checkDigit(str[i]) || str[i]=='.')
        {
            countValid+=1;
        }
    }
    if(countValid==length(str))
    {
        return 1;
    }
    else{
        return 0;
    }
}
int checkZeroes(char temp[])
{
    if(length(temp)==1 && temp[0]=='0')
    {
        return 1;
    }
    if(temp[0]=='0')
    {
        return 0;
    }
    return 1;
}
int validateNumbers(char str[])
{
    int i,number=0,count=0,tempIndex=0;
    char temp[4];
    for(i=0;i<=length(str);i++)
    {
        if(str[i]!='.' && str[i]!='\0')
        {
            temp[tempIndex]=str[i];
            tempIndex++;
            number=number*10+(str[i]-'0');
            //printf("Number : %d\n",number);

        }
        else
        {
            temp[tempIndex]='\0';
            //printf(" temp = %s\n",temp);
            //printf("check zero: %d\n",checkZeroes(temp));
            if(tempIndex==0 || tempIndex>3)
            {
                return 0;
            }
            if((number>=0 && number<=255 ) && checkZeroes(temp))
            {
                count+=1;
                //printf("count valye : %d\n",count);
            }
            else
            {
                return 0;
            }
            tempIndex=0;
            number=0;
            //printf("tempIndex: %d\n",tempIndex);
        }
    }
    //printf("countvlid : %d\n",count);
    if(count==4)
    {
        return 1;
    }
    else{
        return 0;
    }
}
 
int main()
{
    char string[16];
    printf("Enter ipv4 address: \n");
    scanf("%15s",string);
    if(!validateCharacters(string))
    {
        printf("Invalid\n");
    }
    else if(!validateNumbers(string))
    {
        printf("Invalid\n");
    }
    else if(!countSeparator(string))
    {
        printf("Invalid\n");
    }
    else
    {
        printf("Valid\n");
    }
    return 0;
}