//calculate the price of the product by multiplyting the digits in it
//345
//price=3*4*5
import java.util.*;
class Pjava4
{
    public static void main(String arg[])
    {
        Scanner sobj=new Scanner(System.in);
        int n=sobj.nextInt();
        int price=1;
        while(n!=0)
        {
            int digit=n%10;
            price=price*digit;
            n=n/10;
        }
        System.out.print(price);

        

    }
}