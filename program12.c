#include<stdio.h>
float average(int ino1,int ino2,int ino3)
{
    float fans=0.0f;
    fans=((float)(ino1+ino2+ino3)/3);
    return fans;
}
int main()
{
    auto int ivalue1;
    auto int ivalue2;
    auto int ivalue3;
    auto float fRet;

    printf("Enter first number\n");
    scanf("%d",&ivalue1);

    printf("Enter second number\n");
    scanf("%d",&ivalue2);

    printf("Enter third number\n");
    scanf("%d",&ivalue3);


    fRet=average(ivalue1,ivalue2,ivalue3);

    printf("average is %d\n",fRet);

    return 0;
}