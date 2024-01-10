#include<stdio.h>
void Display(int iNo)
{
    int iCnt=0;
    int iCnt2=0;
    
    if(iNo<0)
    {
        iNo=-iNo;
    }
    for (iCnt=1;iCnt<=iNo;iCnt++)
    {
        for(iCnt2=1;iCnt2<=iNo;iCnt2++)
        {
            printf("*");
        }
        printf("#");
    }
}
int main()
{
    int iValue=0;
    printf("Enter number");
    scanf("%d",&iValue);
    Display (iValue);
    return 0;
}