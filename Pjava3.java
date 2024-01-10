//sort the given array in the risk upto 0,1,2 without using sort function
//7
//0 1 1 2 0 2 2
//0 0 1 1 2 2 2
import java.util.*;
class Pjava3
{
    public static void main(String arg[])
    {
        Scanner sobj=new Scanner(System.in);
        int n=sobj.nextInt();

        int arr[]=new int [n];

        for(int i=0;i<n;i++)
        {
            arr[i]=sobj.nextInt();
        }

        int i=0;
        int j=arr.length-1;
        int k=0;

        while(k<=j)
        {
            if(arr[k]==0)
            {
                int temp=arr[i];
                arr[i]=arr[k];
                arr[k]=temp;
                i++;
                k++;
            }
            else if(arr[k]==1)
            {
                k++;
            }
            else if(arr[k]==2)
            {
                int temp=arr[j];
                arr[j]=arr[k];
                arr[k]=temp;
                j--;
            }
        }
        for(int s=0;s<n;s++)
        {
            System.out.print(arr[s]+" ");
        }

    }
}