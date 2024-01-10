#include<stdio.h>
//Logical OR || -> If any of the condition is TRUE then it enters inside the if 
//Logical AND && -> it all of the conditions are TRUE then it enters inside the if
void DisplayClass(float fmarks)
{
    if((fmarks<0.00||(fmarks>100)))
    {
        printf("Invalid marks");
    }
    if((fmarks>=0.0)&&(fmarks<35.00))
    {
        printf("You are fail..\n");
    }
    else if((fmarks>=35.00)&&(fmarks<50.00))
    {
        printf("Your class is pass class..\n");
    }
    else if((fmarks>=50.00)&&(fmarks<60.00))
    {
         printf("Your class is second class..\n");
    }
    else if((fmarks>=60.00)&&(fmarks<75.00))
    {
         printf("Your class is first class class..\n");
    }
    else if((fmarks>=75.00)&&(fmarks<=100.00))
    {
         printf("Your class is first class with distinction..\n");
    }
    
}
int main()
{
    auto float fvalue=0.0f;

    printf("Enter your percentage\n");
    scanf("%f",&fvalue);

    DisplayClass(fvalue);

    return 0;
}