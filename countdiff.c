#include<stdio.h>

int Countdiff(int iNo)
{
  int idigit=0;
  int Esum=0;
  int Osum=0;
  if(iNo<0)
  {
    iNo=-iNo;
  }
  while(iNo>0)
  {
     idigit=iNo%10 ;
     iNo=iNo/10;
    if(idigit%2 == 0)
    {
      Esum=Esum+idigit;
    }
    else
    {
        Osum=Osum+idigit;
    }
  }
  return Esum-Osum;
}
int main()
{
  int iValue=0;
  int iRet=0;

  printf("Enter number");
  scanf("%d",&iValue);

  iRet=Countdiff(iValue);
  
  printf("%d",iRet);

  return 0;
  

}