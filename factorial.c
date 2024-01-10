#include<stdio.h>
int Factorial(int iNo)
{
    int iCnt=0;
    int fact=1;
    if(iNo<0)
    {
        iNo=-iNo;
    }
    for (iCnt=1;iCnt<=iNo;iCnt++)
    {
         fact=fact*iCnt;
    }
    return fact;
}
int main()
{
    int iValue=0,iRet=0;

    printf("Enter number");
    scanf("%d",&iValue);

    iRet=Factorial(iValue);

    printf("Factorial of number is %d",iRet);

    return 0;
}