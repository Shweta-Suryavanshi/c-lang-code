#include<stdio.h>
#include<stdlib.h>
int frequency(int Arr[],int iSize,int iNo)
{
    int iCnt=0;
    int isum=0;
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        if(Arr[iCnt] == iNo)
        {
            isum++;
        }
    }
    return isum;
}
int main()
{
    int iCount=0,iCnt=0,iRet=0,iValue=0;
    int *ptr=NULL;

    printf("Enter number of elements\n");
    scanf("%d",&iCount);

    ptr=(int *)malloc(iCount*sizeof(int));

    printf("Enter the elements\n");
    for(iCnt=0;iCnt<iCount;iCnt++)
    {
        printf("Enter %d element\n",iCnt+1);
        scanf("%d",&ptr[iCnt]);
    }

    printf("Enter number of which you to count frequency");
    scanf("%d",&iValue);
    
    iRet=frequency(ptr,iCount,iValue);
    printf("Frequency of %d is: %d",iValue,iRet);

    return 0;

}