#include<stdio.h>

int Countodd(int iNo)
{
  int idigit=0;
  int iCnt=0;
  if(iNo<0)
  {
    iNo=-iNo;
  }
  while(iNo>0)
  {
     idigit=iNo%10 ;
     iNo=iNo/10;
    if(idigit%2 != 0)
    {
      iCnt++;
    }
  }
  return iCnt;
}
int main()
{
  int iValue=0;
  int iRet=0;

  printf("Enter number");
  scanf("%d",&iValue);

  iRet=Countodd(iValue);
  
  printf("%d",iRet);

  return 0;
  

}