import java.util.*;
import java.lang.*;
import java.io.*;


public class Main
{
 public static void main(String[] args) {
        Scanner sc= new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int N=sc.nextInt();
            int M=sc.nextInt();
            int [][]arr=new int[N][M];
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<M;j++)
                {
                    arr[i][j]=sc.nextInt();
                }
            }
            int count=N*M;
            for(int i=1;i<N-1;i++)
            {
                for(int j=1;j<M-1;j++)
                {
                    int min1=Math.min(N-1-i,M-1-j);
                    int min2=Math.min(i,j);
                    int min3=Math.min(min1,min2)+1;
                    for(int k=1;k<min3;k++)
                    {
                        if(arr[i][j-k]==arr[i][j+k]&&arr[i-k][j]==arr[i+k][j])
                            count+=1;
                        else
                            break;
                    }
                }
            }
            System.out.println(count);
        }
    }
}
