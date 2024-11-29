#include <stdio.h>
#include <ctype.h>
int main()
{
    char st[100];
    printf("Enter the string: ");
    scanf("%[^\n]",st);
    int num_arr[100],ind_num=0;
    char op_arr[100];
    int ind_op=0;
    int dig=0;
    int flg=0;
    for (int i=0;st[i]!='\0';i++)
    {
        char c=st[i];
        if(c==' ')
        {
            continue;
        }
        if(isdigit(c))
        {
            dig=dig*10+(c-'0');
            flg=1;
        }
        else
        {
            if(flg)
            {
                num_arr[ind_num++]=dig;
                dig=0;
                flg=0;
            }
            if(c=='+'||c=='-'||c=='*'||c=='/')
            {
                op_arr[ind_op++]=c;
            }
            else
            {
                printf("Invalid Expression.");
                return 1;
            }
        }
    }
    if(flg)
    {
        num_arr[ind_num++]=dig;
    }
    for(int j=0;j<ind_op;j++)
    {
        if(op_arr[j]=='/')
        {
            if(num_arr[j+1]==0)
            {
                printf("Zero division error.");
            }
            num_arr[j]=num_arr[j]/num_arr[j+1];
            for(int k=j+1;k<ind_num-1;k++)
            {
                num_arr[k]=num_arr[k+1];
            }
            for(int l=j;l<ind_op-1;l++)
            {
                op_arr[l]=op_arr[l+1];
            }
            ind_num--;
            ind_op--;
            j--;
        }
    }
    for(int i=0;i<ind_op;i++)
    {
        if(op_arr[i]=='*')
        {
            num_arr[i]=num_arr[i]*num_arr[i+1];
            for(int k=i+1;k<ind_num-1;k++)
            {
                num_arr[k]=num_arr[k+1];
            }
            for(int l=i;l<ind_op-1;l++)
            {
                op_arr[l]=op_arr[l+1];
            }
            ind_num--;
            ind_op--;
            i--;
        }
    }
    int ans=num_arr[0];
        for(int i=0;i<ind_op;i++)
        {
            if(op_arr[i]=='+')
            {
                ans=ans+num_arr[i+1];
            }
            else if(op_arr[i]=='-')
            {
                ans=ans-num_arr[i+1];
            }
        }
    printf("Ans: %d\n",ans);
    return 0;
}