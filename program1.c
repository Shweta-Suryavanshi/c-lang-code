//Accept 2 values from user and perform addition.
#include<stdio.h>
//addition is function which accepts 2 parametrs of type integer and returns integer

////////////////////////////////////////////////////////////
//
// function name:  addition
//description:     it is used to perform addition of 2 integers
//input argument:  integer,integer
//output:          integer
//author:          Shweta Dnyaneshwar Suryavanshi
//date:            25/09/23
//
////////////////////////////////////////////////////////////
int addition(int no1,int no2)
{
    int ans=0;
    ans=no1+no2;
    return ans;
}
////////////////////////////////////////////////////////////
//
// entry point function of an application which perform addition
//
///////////////////////////////////////////////////////////
int main()
{
   int num1=0;
   int num2=0;
   int sum=0;
    printf("Enter first no.:-\n ");
    scanf("%d",&num1);

    printf("Enter second no.:- \n");
    scanf("%d",&num2);

    sum=addition(num1,num2);//function call to perform addition
    printf("Addition of two no is %d",sum);


    return 0;
}
/*
test cases
case1
 input 10 20
output 30
case2
 input 10 0
output 10
case3
 input 10 -5
output 5
case1
 input -10 -5
output -15

*/