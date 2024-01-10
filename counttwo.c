#include<stdio.h>

int CountTwo(int iNo)
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
    if(idigit==2)
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

  iRet=CountTwo(iValue);
  
  printf("%d",iRet);

  return 0;
  

}