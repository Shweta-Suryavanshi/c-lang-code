#include <stdio.h>
float CalculatePercentage(int imarks, int itotal)
{
    auto float fpercentage=0.0f;

    if((imarks<0)|| (itotal<0)||(imarks>itotal) )
    {
        printf("Invalid input\n");
        return fpercentage;
    }
    
    fpercentage=(((float)imarks/(float)itotal)*100);
    return fpercentage;
}
int main()
{
    auto int ivalue1=0;
    auto int ivalue2=0;
    auto float fRet=0.0f;

    printf("Enter the marks obtained\n");
    scanf("%d",&ivalue1);

    printf("Enter the total marks\n");
    scanf("%d",&ivalue2);

    fRet=CalculatePercentage(ivalue1,ivalue2);
    printf("Your percentage is %f \n",fRet);

    return 0;
    }