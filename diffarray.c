//program to find difference between summation of even and odd elements of an array.
#include<stdio.h>
#include<stdlib.h>
int DiffArray(int Arr[],int iSize)
{
    int iCnt=0,evensum=0,oddsum=0;
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        if(Arr[iCnt]%2 == 0)
        {
             evensum=evensum+Arr[iCnt];
        }
        else
        {
             oddsum=oddsum+Arr[iCnt];
        }
    }
    return evensum-oddsum;
}
int main()
{
    int iCount=0,iCnt=0,iRet=0;
    int *ptr=NULL;

    printf("Enter number of elements");
    scanf("%d",&iCount);

    ptr=(int *)malloc(iCount*sizeof(int));

    printf("Enter elements\n");
    for(iCnt=0;iCnt<iCount;iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    iRet=DiffArray(ptr,iCount);
    printf("Difference of even elements and odd elements of array is %d",iRet);
    free(ptr);

    return 0;
}