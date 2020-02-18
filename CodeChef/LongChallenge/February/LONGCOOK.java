/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        boolean []leapYearArray = new boolean[401];
        for(int i=1;i<401;i++)
        {
            if(i%4==0)
            {
                if(i%100==0)
                {
                    if(i%400==0)
                        leapYearArray[i]=true;
                    else
                        leapYearArray[i]=false;
                }
                else
                    leapYearArray[i]=true;
            }
            else
                leapYearArray[i]=false;
        }
        int []febDate = new int[401];
        febDate[1]=2;
        for(int i=2;i<401;i++)
        {
            if(leapYearArray[i-1]==true)
            {
                febDate[i]=febDate[i-1]-2;
                if(febDate[i]<=0)
                    febDate[i]= (febDate[i]+7) %8;
            }
            else {
                febDate[i] = febDate[i - 1] - 1;
                if(febDate[i]<=0)
                    febDate[i]= (febDate[i]+7) %8;
            }
        }
        int []overlap = new int[401];
        for(int i=1;i<401;i++)
        {
            if(febDate[i]==7)
                overlap[i]=1;
            if(febDate[i]==6)
            {
                if(!leapYearArray[i])
                    overlap[i]=1;
            }
        }
        for(int i=1;i<401;i++)
        {
            overlap[i]+=overlap[i-1];
        }
        int val = overlap[400]-overlap[0];

        int t=sc.nextInt();
        while(t-->0)
        {
            int m1=sc.nextInt();
            int y1=sc.nextInt();
            int m2=sc.nextInt();
            int y2=sc.nextInt();
            long result=0;
            if(m1>2)
                y1++;
            if(m2<2)
                y2--;
            long val1=overlap[y2%400]+((long)(y2/400)*val);
            long val2=overlap[(y1-1)%400]+((long)((y1-1)/400)*val);
            result = val1-val2;
            System.out.println(result);
        }

    }
}
