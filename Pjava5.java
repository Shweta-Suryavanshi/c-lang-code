//riverse the given no 
//234
//432
import java.util.*;
class Pjava5
{
    public static void main(String arg[])
    {
        Scanner sobj=new Scanner(System.in);
        int n=sobj.nextInt();
        int rev=0;
        while(n!=0)
        {
            int digit=n%10;
            rev=rev*10+digit;
            n=n/10;
        }
        System.out.print(rev);
    }
}