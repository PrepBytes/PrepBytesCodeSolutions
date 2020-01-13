import java.util.*;
import java.lang.*;
import java.io.*;

public class Main
{
  public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int q = sc.nextInt();
        int[] arr = new int[n + 1];
        for(int i=1;i<n+1;i++)
            arr[i]=sc.nextInt();
        int incRange[] = new int[n + 1];
        int j = 1;
        Set<Integer> range = new HashSet<>();
        for (int i = 2; i <n+1;i++) {
            if (arr[i - 1] < arr[i] && (i + 1 == n + 1 || arr[i] > arr[i + 1])) {
                incRange[i]++;
                range.add(i);
            }
        }
        for(int i=2;i<n+1;i++)
            incRange[i]=incRange[i]+incRange[i-1];
        int decRange[]=new int[n+1];
            for(int i=2;i<n+1;i++)
            {
                if(arr[i-1]>arr[i]&&(i+1==n+1||arr[i]<arr[i+1])) {
                    decRange[i]++;
                    range.add(i);
                }

            }
        for(int i=2;i<n+1;i++)
            decRange[i]=decRange[i]+decRange[i-1];
         for(int i=1;i<=q;i++)
         {
             int l=sc.nextInt();
             int r=sc.nextInt();
             if(range.contains(r))
             {
                 if(incRange[r]-incRange[l]==decRange[r]-decRange[l])
                     System.out.println("YES");
                 else
                     System.out.println("NO");
             }
             else
             {
                 if(arr[r]>arr[r-1])
                 {
                     if(incRange[r]-incRange[l]+1==decRange[r]-decRange[l])
                         System.out.println("YES");
                     else
                         System.out.println("NO");
                 }
                 else
                 {
                     if(arr[r]<arr[r-1])
                     {
                         if(incRange[r]-incRange[l]==decRange[r]-decRange[l]+1)
                             System.out.println("YES");
                         else
                             System.out.println("NO");
                     }
                 }
             }
         }
    }
}
