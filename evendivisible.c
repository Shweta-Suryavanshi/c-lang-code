#include<stdio.h>
#include<stdlib.h>
void divisiblearray(int Arr[],int iSize)
{
    int iCnt=0;
    int idigit=0;

    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        idigit=Arr[iCnt]%10;
        if(idigit==0)
        {
            printf(" %d\t",Arr[iCnt]);
        }
    }
}
int main()
{
    int iCount=0;
    int *ptr=NULL;
    int iCnt=0;

    printf("Enter number of elements\n");
    scanf("%d",&iCount);

    ptr=(int *)malloc(iCount*sizeof(int));

    if(ptr == NULL)
    {
        printf("Unable to allocate memory");
        return -1;
    }

    printf("Enter elements\n");
    for(iCnt=0;iCnt<iCount;iCnt++)
    {
        scanf("%d",&ptr[iCnt]);
    }

    divisiblearray(ptr,iCount);
}
