#include<stdio.h>
#define pi 3.14
float calculateArea(float no1)
{
    auto float area =0.0f;
    
    area =pi*no1*no1;
    return area;
}
int main()
{
    auto float radius=0.0f;
    auto float ans;
    printf("Enter radius\n");
    scanf("%f",&radius);

    ans=calculateArea(radius);
    printf("area is: %f\n",ans);
    return 0;
    
}