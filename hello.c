//Accept one number from user and if number is less than 10 then print Hello otherwise print Demo.
#include<stdio.h>
void display(int iNo)
{
    if(iNo<10)
    {
        printf("Hello");
    }
    else
    {
        printf("Demo");
    }
}
int main()
{
    int iValue=0;

    printf("Enter number\n");
    scanf("%d",&iValue);

    display(iValue);

    return 0;
}