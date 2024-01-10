#include<stdio.h>
int EvenFactorial(int iNo)
{
    int ifact=1;
    int iCnt=0;
    if (iNo<0)
    {
        iNo=-iNo;
    }
    for(iCnt=1;iCnt<=iNo;iCnt++)
    {
       if(iCnt%2 == 0)
       {
         ifact=ifact*iCnt;
       }
    }
    return ifact;
}
int main()
{
    int iValue=0,iRet=0;

    printf("Enter number");
    scanf("%d",&iValue);

    iRet=EvenFactorial(iValue);

    printf("Even factorial of number is %d",iRet);

    return 0;
}