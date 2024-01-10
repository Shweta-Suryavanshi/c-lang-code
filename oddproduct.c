#include<stdio.h>
#include<stdlib.h>
int product(int Arr[],int iSize)
{
    int iCnt=0;
    int product=1;
    
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        if(Arr[iCnt]%2 != 0)
        {
           product=product* Arr[iCnt];
        }
    }
    return product;
    
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

    
    
    iRet=product(ptr,iCount);
    printf("product of odd elements is: %d",iRet);

    return 0;

}