#include<stdio.h>
int Multiply(int iNo1,int iNo2,int iNo3)
{
    int imult=0;
    imult=iNo1*iNo2*iNo3;
    return imult;
}
int main()
{
    int iValue1=0,iValue2=0,iValue3=0,iRet=0;
    printf("Please enter three numbers\n");
    scanf("%d %d %d",&iValue1,&iValue2,&iValue3);
    iRet=Multiply(iValue1,iValue2,iValue3);
    printf("Multiplication is %d",iRet);
    return 0;
}