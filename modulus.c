#include<stdio.h>
#include<stdlib.h>
int validateInput(int result) 
{
    if (result != 1) {
        printf("Invalid input.\n");
        return 0;
    }
    return 1;
}
long long calculate_result(long long base,long long exponent,long long modulus)
{
    long long answer=1;
    base=base%modulus;
    while(exponent>0)
    {
        if (exponent%2==1)
        {
            answer=(answer*base)%modulus;
        }
        base=(base*base)%modulus;
        exponent=exponent/2;
    }
    return answer;
}
int main()
{
    long long  Base,Exponent,Modulus,final_answer;
    printf("Enter Base: ");
    if(!validateInput(scanf("%lld",&Base))||Base<=0)
    {
        printf("Base should be positive integer.\n");
        return 1;
    }
    printf("Enter Exponent: ");
    if(!validateInput(scanf("%lld",&Exponent))||Exponent<0)
    {
        printf("Exponent should be positive integer.\n");
        return 1;
    }
    printf("Enter Modulus: ");
    if(!validateInput(scanf("%lld",&Modulus))||Modulus<=1)
    {
        printf("Modulus should be greater than 1.\n");
        return 1;
    }
    final_answer=calculate_result(Base,Exponent,Modulus);
    printf("Answer: %lld\n", final_answer);

    return 0;

}