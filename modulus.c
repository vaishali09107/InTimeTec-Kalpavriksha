#include<stdio.h>
#include<stdlib.h>
void validateInput(int result) 
{
    if (result != 1) {
        printf("Wrong Value.\n");
        exit(1);
    }
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
    validateInput(scanf("%lld", &Base));
    printf("Enter Exponent: ");
    validateInput(scanf("%lld", &Exponent));
    printf("Enter Modulus: ");
    validateInput(scanf("%lld", &Modulus));

    if (Base<0)
    {
        printf("Base should be greater than Zero.\n");
        exit(1);
    }
    if (Exponent<0)
    {
        printf("Exponent should be greater than Zero.\n");
        exit(1);
    }
    if (Modulus<=1)
    {
        printf("Modulus should be greater than or equlas to one.\n");
        exit(1);
    }
    final_answer=calculate_result(Base,Exponent,Modulus);
    printf("Answer: %lld\n", final_answer);

    return 0;

}