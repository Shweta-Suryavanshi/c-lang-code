//if n people entering and m people are leaving the boat every hour code to find the maximum number of people to stay on boat
//givin time t=5
//[7,0,5,1,3]
//[1,2,1,3,4]
//ANS=8
import java.util.*;
class Pjava1
{
    public static void main(String arg[])
    {
        Scanner sc=new Scanner(System.in);
        int noOfHours =sc.nextInt();
        int E[]=new int[noOfHours];
        int L[]=new int [noOfHours];

        for(int i=0;i<E.length;i++)
        {
            E[i]=sc.nextInt();
        }
        for(int i=0;i<L.length;i++)
        {
            L[i]=sc.nextInt();
        }

        int max=Integer.MIN_VALUE;
        int currsum=0;
        for(int i=0;i<noOfHours;i++)
        {
            currsum=currsum+E[i]-L[i];
            max=Math.max(max,currsum);
        }
        System.out.println(max);
    }
}