//program to print "Jay Ganesh" 5 times
#include <stdio.h>
void display(int iNo)
{
    int iCnt=0;
   
    //     1      2       3
    for(iCnt=1;iCnt<=iNo;iCnt++)
    {
        printf("Jay Ganesh\n"); //4
    }
}
int main()
{
    display(8);
    return 0;
}