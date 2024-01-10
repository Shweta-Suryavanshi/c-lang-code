#include<stdio.h>
int CalculateCube(int num)
{
    int cube=0;
    cube =(num * num * num);
    return cube ;
}
int main()
{
    int no=0;
    int ans=0;

    printf("Enter a number\n");
    scanf("%d",&no);

    ans=CalculateCube(no);
    printf("Cube of number is %d\n",ans);
    
    return 0;

}