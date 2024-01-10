//program to find 3 digit number
#include<stdio.h>
#include<stdlib.h>
int digit(int Arr[],int iSize)
{
    int iCnt=0;
    int iDigit=0,iNo=0,isum=0;
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        while(Arr[iCnt] != 0)
        {
                Arr[iCnt]=Arr[iCnt]/10;
                iCnt=iCnt+1;
        }
        if(iCnt == 3)
        {
           printf("%d\t",Arr[iCnt]);
        }     
    }
}
int main()
{
    int iCount=0,iCnt=0;
    int *ptr=NULL;

    printf("Enter number of elements\n");
    scanf("%d",&iCount);

    ptr=(int *)malloc(iCount*sizeof(int));

    if(ptr == NULL)
    {
        printf("Unable to allocate memory");
    }

    printf("Enter the elements\n");
    for(iCnt=0;iCnt<iCount;iCnt++)
    {
        printf("Enter %d element\n",iCnt+1);
        scanf("%d",&ptr[iCnt]);
    }

    digit(ptr,iCount);

    free(ptr);

    return 0;

}