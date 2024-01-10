//program to find product of odd elements from the array
#include<stdio.h>
#include<stdlib.h>
int indexelement(int Arr[],int iSize)
{
    int iCnt=0;
    int mult=1;
    
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        if(Arr[iCnt]%2 != 0)
        {
            mult=mult*Arr[iCnt];
        }
        
    }
    return mult;
    
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
    
    iRet=indexelement(ptr,iCount);
    printf("Product is %d :",iRet);
    
    return 0;

}