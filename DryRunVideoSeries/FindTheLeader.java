import java.util.*;
import java.io.*;

public class Main {
  public static void main(String args[]) throws IOException {
    Scanner sc= new Scanner(System.in);
    int t=sc.nextInt();
    // Test case loop
    while(t-->0)
    {
      int n=sc.nextInt();
      int []arr = new int[n];
      // Taking array input
      for(int i=0;i<n;i++)
      {
        arr[i]=sc.nextInt();
      }
      // Assigning the last element as current leader
      int curr_leader = arr[n-1];
      System.out.print(curr_leader+" ");
      // Checking each element with the current leader, and updating the leader when required
      for(int i=n-2;i>=0;i--)
      {
        if(arr[i]>=curr_leader)
        {
          curr_leader=arr[i];
          // Printing the current leader
          System.out.print(curr_leader+" ");
        }
      }
      System.out.println();
    }
    
  }
}
