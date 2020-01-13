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
            int n=sc.nextInt();
            long a=sc.nextLong();
            long val = (long)Math.pow(10,n)-1;
            long s=2*val+a+2;
            System.out.println(s);
            long b=sc.nextLong();
            long c=s-(a+b)-val-1;
            System.out.println(c);
            long d=sc.nextLong();
            long e=s-(a+b+c+d);
            System.out.println(e);
            int res=sc.nextInt();
            if(res==-1)
                System.exit(0);
        }
    }
}
