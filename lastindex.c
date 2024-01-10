//program to find index of last occurance of number
#include<stdio.h>
#include<stdlib.h>
int indexelement(int Arr[],int iSize,int iNo)
{
    int iCnt=0;
    
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            return iCnt-2;
        }
        else
        {
            return -1;
        }
    }
    
}
int main()
{
    int iCount=0,iCnt=0,iRet=0,iValue=0;
    int *ptr=NULL;

    printf("Enter number of elements\n");
    scanf("%d",&iCount);

    ptr=(int *)malloc(iCount*sizeof(int));

    if(ptr == NULL)
    {
        printf("Unable to allocate memory");
        return-1;
    }

    printf("Enter the elements\n");
    for(iCnt=0;iCnt<iCount;iCnt++)
    {
        printf("Enter %d element\n",iCnt+1);
        scanf("%d",&ptr[iCnt]);
    }

    printf("Enter number of which you to count index");
    scanf("%d",&iValue);
    
    iRet=indexelement(ptr,iCount,iValue);
    
    if(iRet == -1)
    {
        printf("there is no such number");
    }
    else
    {
        printf("index of last  %d is: %d",iValue,iRet);
    }

    return 0;

}