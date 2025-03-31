#include <stdio.h>
#include <ctype.h>
#include<stdlib.h>



int is_operator(char c)
{
    return (c=='+'||c=='-'||c=='*'||c=='/');
}

int check_valid_expression(char *expression)
{
    int is_previous_operator=0,i;
    for(i=0; expression[i]!='\0'; i++)
    {
        char c=expression[i];
        if(is_operator(c))
        {
            if(is_previous_operator)
            {
                return 0;
            }
            is_previous_operator=1;
        }
        else
        {
            is_previous_operator=0;
        }
    }
    return 1;
}

void parse_expression(char *expression, int *number_array,char *operator_array,int *number_index, int *operator_index)
{
    int digit=0,flag=0,i;
    for( i =0; expression[i]!='\0'; i++)
    {
        char character=expression[i];
        if(character==' ')
        {
            continue;
        }
        if(character>='0' && character<='9')
        {
            digit=digit*10+(character-'0');
            flag=1;
        }
        else
        {
            if(flag)
            {
                number_array[*number_index]=digit;
                (*number_index)++;
                digit=0;
                flag=0;
            }
            if(is_operator(character))
            {
                operator_array[*operator_index]=character;
                (*operator_index)++;
            }
            else
            {
                printf("Invalid Expression.\n");
                exit(1);
            }
        }
    }
    if(flag)
    {
        number_array[*number_index] = digit;
        (*number_index)++;
    }
}
void high_precendence_operations(int *number_array,char *operator_array,int *number_index, int *operator_index)
{
    int i,j,k;
    for(i=0;i< *operator_index;i++)
    {
        if(operator_array[i]=='/' || operator_array[i]=='*')
        {
            if(operator_array[i]=='/')
            {
                if(number_array[i+1]==0)
                {
                    printf("Zero Divison Error.\n");
                    exit(1);
                }
                number_array[i]=number_array[i]/number_array[i+1];
            }
            else if(operator_array[i]=='*')
            {
                number_array[i]=number_array[i]*number_array[i+1];
            }
            for(j=i+1;j< *number_index-1;j++)
            {
                number_array[j]=number_array[j+1];
            }
            for(k=i; k< *operator_index;k++)
            {
                operator_array[k]=operator_array[k+1];
            }
            (*number_index)--;
            (*operator_index)--;
            i--; 
        }
    }
}

int low_precedence_operations(int *number_array,char *operator_array, int operator_index) 
{
    int result = number_array[0],i;
    for (i = 0; i < operator_index; i++) {
        if (operator_array[i] == '+') 
        {
            result = result + number_array[i + 1];
        } 
        else if (operator_array[i] == '-') 
        {
            result = result - number_array[i + 1];
        }
    }
    return result;
}

int main()
{
    char *expression= NULL,character;
    int size=0,capacity=20;
    expression=(char *)malloc(capacity * sizeof(char));
    if(expression==NULL)
    {
        printf("Error in memory allocation.\n");
        return 1;
    }
    printf("Enter the input string: ");
    while(scanf("%c",&character)==1 && character!='\n')
    {
        expression[size++]=character;
        if (size>=capacity)
        {
            capacity*=2;
            char *temp=realloc(expression,capacity * sizeof(char));
            if (temp==NULL)
            {
                printf("Memory Re-Allocation Failed.\n");
                free(expression);
                return 1;
            }
            expression=temp;
        }
    }
    expression[size]='\0';
    if(!check_valid_expression(expression))
    {
        printf("Invalid Expression.\n");
        free(expression);
        return 1;
    }
    int *number_array=(int *)malloc(sizeof(int) * capacity);
    char *operator_array=(char *)malloc(sizeof(char) * capacity);
    if (number_array==NULL || operator_array==NULL)
    {
        printf("Memory Allocation Failed.\n");
        free(expression);
        return 1;
    }
    int number_index=0,operator_index=0;
    parse_expression(expression,number_array,operator_array,&number_index,&operator_index);
    high_precendence_operations(number_array,operator_array,&number_index,&operator_index);
    int ans=low_precedence_operations(number_array,operator_array,operator_index);
    printf("Ans : %d\n",ans);
    free(expression);
    free(number_array);
    free(operator_array);
    return 0;
}
