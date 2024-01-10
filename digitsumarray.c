//program to find 3 digit //program to find difference between maximum element and minmum element from the array.
#include<stdio.h>
#include<stdlib.h>
int digitsum(int Arr[],int iSize)
{
    int iCnt=0,iDigit=0,iNo=0,sum=0;
    
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        while(Arr[iCnt]>0)
        {
        iDigit=Arr[iCnt]%10;
        sum=sum +iDigit;
        iNo=Arr[iCnt]/10;
        
        }
        return sum;
    }
    
    
}
int main()
{
    int iCount=0,iCnt=0,iRet=0,iValue1=0,iValue2;
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

    
    
    iRet=digitsum(ptr,iCount);
    printf("sum of elements is: %d",iRet);

    return 0;

}