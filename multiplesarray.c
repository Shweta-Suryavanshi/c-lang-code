#include<stdio.h>
#include<stdlib.h>
void multiplesArray(int Arr[],int iSize)
{
    int iCnt=0;
    for(iCnt=0;iCnt<iSize;iCnt++)
    {
        if(Arr[iCnt]%11 == 0)
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

    printf("Enter the elements\n");
    for(iCnt=0;iCnt<iCount;iCnt++)
    {
        printf("Enter %d element\n",iCnt+1);
        scanf("%d",&ptr[iCnt]);
    }
    
    multiplesArray(ptr,iCount);

    return 0;

}