import java.util.*;
import java.io.*;

public class Main {
  public static void main(String args[]) throws IOException {
    
    //write your code here
    Scanner sc = new Scanner(System.in);
    int t=sc.nextInt(); // declare and initialize test case variable
    while(t-->0)
    {
      // variable n to store the input, sum and rem for calculation
      int n=sc.nextInt();
      int sum=0,rem;
      
      //loop to get all the factors except the number itself and add them
      for(int i=1;i<=n/2;i++)
      {
        rem=n%i;
        if(rem==0)
          sum+=i;
      }
      
      //System.out.println(sum); debugging statement
      
      //if the sum is equal to n, print true else false
      if(sum==n)
        System.out.println("true");
      else
        System.out.println("false");  
    }
    
  }
}
