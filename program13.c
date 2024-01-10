#include<stdio.h>
int maximum(int ino1,int ino2,int ino3)
{
    if((ino1>=ino2)&&(ino1>=ino3))
    {
        return ino1;
    }
    else if ((ino2>=ino1)&&(ino2>=ino3))
    {
        return ino2;
    }
    else
    {
        return ino3;
    }
}
int main()
{
    auto int ivalue1;
    auto int ivalue2;
    auto int ivalue3;
    auto int iRet;

    printf("Enter first number\n");
    scanf("%d",&ivalue1);

    printf("Enter second number\n");
    scanf("%d",&ivalue2);

    printf("Enter third number\n");
    scanf("%d",&ivalue3);


    iRet=maximum(ivalue1,ivalue2,ivalue3);

    printf("maximum is %d\n",iRet);

    return 0;
}