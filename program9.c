#include<stdio.h>
void DisplayTime(int istandard)
{
    if (istandard==1)
    {
        printf("Your exam is at 8 AM");
    }
    else if(istandard==2)
    {
         printf("Your exam is at 9 AM");
    }
    else if(istandard==3)
    {
         printf("Your exam is at 10 AM");
    }
    else if(istandard==4)
    {
         printf("Your exam is at 11 AM");
    }
    else if(istandard==5)
    {
         printf("Your exam is at 12 AM");
    }
    else
    {
         printf("Invalid input");
    }
    
}
int main()
{
    auto int ivalue=0;
    
    printf("Enter your standard\n");
    scanf("%d",&ivalue);

    DisplayTime(ivalue);

    return 0;
}