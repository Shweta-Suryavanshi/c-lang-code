#include<stdio.h>
float Percentage(int iNo1,int iNo2)
{
    float percent=0.0f;
    
    if(iNo1 ==0)
    {
        printf("Total marks can't be zero\n");
    }
    else
    {
        percent=(((float)iNo2/(float)iNo1)*100);
    }
    
    return percent;
}
int main()
{
    int iValue1=0,iValue2=0;
    float fRet=0.0;

    printf("Please Enter total marks");
    scanf("%d",&iValue1);

    printf("Please Enter obtained marks");
    scanf("%d",&iValue2);

    fRet=Percentage(iValue1,iValue2);

    printf("Percentage is %f",fRet);

    return 0;
}