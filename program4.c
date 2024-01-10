#include<stdio.h>
#include<stdbool.h>

int checkeven(int no)
{
    if(no%2==0)
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
    int value=0;
    bool bRet=false;
    printf("Enter a number");
    scanf("%d",&value);
     bRet=checkeven(value);
     if(bRet==true)
     {
        printf("%d is even",value);
     }
     else
     {
        printf("%d is odd",value);
     }
     
     
     return 0;
}