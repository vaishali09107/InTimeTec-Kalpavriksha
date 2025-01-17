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

void compression(char *string,char **result)
{
	char ch;
	*result=(char *)malloc(100 * sizeof(char));
	int i;
	int resultIndex=0;
	int count=1;

	for(i=0; i<length(string); i++)
	{


		if(string[i+1]==string[i])
		{
			count++;
		}
		else
		{
			(*result)[resultIndex++]=string[i];
			(*result)[resultIndex++]=count+'0';
			count=1;
		}
	}
	(*result)[resultIndex]='\0';
}

int main()
{
	char *string=(char *)malloc(100 *sizeof(char));
	if(string==NULL)
	{
		return 1;
	}
	char *result=NULL;

	scanf("%[^\n]",string);
	printf("input: %s\n",string);

	compression(string,&result);
	if(length(result)==length(string))
	{
		
		printf("compressed: %s",result);
	}
	else
	{
		printf("compressed: %s",string);
	}

	return 0;
}