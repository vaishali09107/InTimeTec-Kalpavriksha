#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main()
{
    char expr[100];
    printf("Enter mathematical expression: ");
    scanf(" %[^\n]", expr);

    int num_arr[100];
    int n_in = 0;
    char op_arr[100];
    int op_in = 0;

    int dig = 0;
    int flg = 0;
    for(int i=0;expr[i]!='\0';i++)
    {
        if (isspace(expr[i]))
        {
            continue;
        }
        else if(isdigit(expr[i]))
        {
            dig=dig*10+(expr[i]-'0');
            flg=1;
        }
        else if(expr[i]=='/'||expr[i]=='*'||expr[i]=='+'||expr[i]=='-')
        {
            if(flg)
            {
                num_arr[n_in++]=dig;
                dig=0;
                flg=0;
            }
            op_arr[op_in++]=expr[i];
        }
        else
        {
            printf("Error: Invalid expression.",expr[i]);
            return 1;
        }
    }
    if(flg)
    {
        num_arr[n_in++]=dig;
    }
    for(int i=0;i<op_in;i++)
    {
        if(op_arr[i]=='*')
        {
            num_arr[i]=num_arr[i]*num_arr[i + 1];
            for(int j=i+1;j<n_in-1;j++)
            {
                num_arr[j]=num_arr[j+1];
            }
            for(int j=i;j<op_in-1;j++)
            {
                op_arr[j]=op_arr[j+1];
            }
            n_in--;
            op_in--;
            i--;
        }
        else if(op_arr[i]=='/')
        {
            if(num_arr[i+1]==0)
            {
                printf("Error: Division by zero.\n");
                return 1;
            }
            num_arr[i]=num_arr[i]/num_arr[i+1];
            for(int j=i+1;j<n_in-1;j++)
            {
                num_arr[j]=num_arr[j+1];
            }
            for(int j=i;j<op_in-1;j++)
            {
                op_arr[j]=op_arr[j+1];
            }
            n_in--;
            op_in--;
            i--;
        }
    }
    int ans=num_arr[0];
    for(int i=0;i<op_in;i++)
    {
        if(op_arr[i] == '+')
        {
            ans+=num_arr[i+1];
        }
        else if(op_arr[i]=='-')
        {
            ans-=num_arr[i+1];
        }
    }

    printf("ANS : %d\n", ans);
    return 0;
}