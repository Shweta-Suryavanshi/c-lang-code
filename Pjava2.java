//array of integer n having risk [0 1 2] then sort the array in increasing risks
//givin time t=5
//[1 0 2 2 0 1 1 0 ]
//ans=[0 0 0  1 1 1 2 2]

import java.util.*;
class Pjava2
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