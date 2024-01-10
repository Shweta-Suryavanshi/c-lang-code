#include<stdio.h>
#include<stdbool.h>

bool ChkZero(int iNo)
{
  int idigit=0;
  if(iNo<0)
  {
    iNo=-iNo;
  }
  while(iNo>0)
  {
     idigit=iNo%10 ;
     iNo=iNo/10;
    if(idigit==0)
    {
      return true;
    }
  }
  return false;
}
int main()
{
  int iValue=0;
  bool iRet=false;

  printf("Enter number");
  scanf("%d",&iValue);

  iRet=ChkZero(iValue);
  if(iRet== true)
  {
    printf("It contains zero");
  }
  else
  {
    printf("There is no zero");
  }
  return 0;

}