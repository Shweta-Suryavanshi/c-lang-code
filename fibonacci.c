

/*
#include<stdio.h>
void arm(int iNo)
{
  int idigit=0;
  int sum=0;
  int iCnt=0;
  //int temp=0;
  //temp=iNo;
  for(iCnt=1;iCnt=iNo;iCnt++)
  {
    idigit=iNo%10;
    //idigit=idigit*idigit*idigit;
    sum=sum+idigit;
    iNo=iNo/10;
    
  }
  printf("%d",sum);
  
  if(sum==temp)
  {
    printf("Arm");
  }
  else
  {
    printf("Mot arm");
  }

}
int main()
{
  int iValue=0;
  printf("Enter number");
  scanf("%d",&iValue);
  arm(iValue);
  return 0;
  
}
*/


/*
#include<stdio.h>
void fact(int iNo)
{
  int iCnt=0;
  int fact=1;
  for(iCnt=1;iCnt<=iNo;iCnt++)
  {
    fact=fact*iCnt;
    
  }
  printf("%d",fact);
}
int main()
{
  int iValue=0;
  printf("Enter number");
  scanf("%d",&iValue);
  fact(iValue);
  return 0;
}
*/




/*
#include<stdio.h>
#include<stdbool.h>
//typedef void bool;
//#define true 1
//#define false 0
bool isprime(int iNo)
{
  int iCnt=0;
  for(iCnt=2;iCnt<iNo;iCnt++)
  {
    if(iNo%iCnt == 0)
    {
      return false;
    }
    
  }
  return true ;
}
int main()
{
  int iValue=0;
  bool iRet=false;

  printf("Enter number");
  scanf("%d",&iValue);

  iRet=isprime(iValue);
  if(iRet== true)
  {
    printf("Prime");
  }
  else
  {
    printf("Not prime");
  }
  return 0;

}
*/


/*
#include<stdio.h>
#include<stdbool.h>

bool ispalindrome(int iNo)
{
  int idigit=0;
  int isum=0;
  int temp=0;
  temp=iNo;

  while(iNo>0)
  {
     idigit=iNo%10 ;
     isum=(isum*10)+idigit;
     iNo=iNo/10;
  
  }
  if(temp==isum)
  {
    return true;
  }
  else 
  {
    return false;
  }
}
int main()
{
  int iValue=0;
  bool iRet=false;

  printf("Enter number");
  scanf("%d",&iValue);

  iRet=ispalindrome(iValue);
  if(iRet== true)
  {
    printf("Palindrome");
  }
  else
  {
    printf("Not palindrome");
  }
  return 0;

}*/