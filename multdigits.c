#include<stdio.h>

int MultDigits(int iNo)
{
  int idigit=0;
  int mult=1;
  if(iNo<0)
  {
    iNo=-iNo;
  }
  while(iNo>0)
  {
     idigit=iNo%10 ;
     iNo=iNo/10;
    mult=mult*idigit;
  }
  return mult;
}
int main()
{
  int iValue=0;
  int iRet=0;

  printf("Enter number");
  scanf("%d",&iValue);

  iRet=MultDigits(iValue);
  
  printf("%d",iRet);

  return 0;
  

}