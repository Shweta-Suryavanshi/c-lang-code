#include<stdio.h>
#include<stdlib.h>
int frequency(int Arr[],int iSize)
{
    int iCnt=0,evenelement=0;
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        if(Arr[iCnt]%2==0)
        {
            evenelement++;
        }
    }
    return evenelement;
}
int main()
{
    int iCount=0;
    int *ptr=NULL;
    int iCnt=0,iRet=0;

    printf("Enter number of elements\n");
    scanf("%d",&iCount);

    ptr=(int *)malloc(iCount*sizeof(int));

    if(iCount == 0)
    {
        printf("Unable to allocate memory");
        return -1;
    }

    printf("Enter elements\n");
    for(iCnt=0;iCnt<iCount;iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    iRet=frequency(ptr,iCount);
    printf("Frequency of even elements is %d",iRet);
    free(ptr);
}
