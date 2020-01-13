import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int s=sc.nextInt();
            int w1=sc.nextInt();
            int w2=sc.nextInt();
            int w3=sc.nextInt();
            int sum,sum1,sum2;
            sum=w1+w2+w3;
            if(s>=sum)
                System.out.println("1");
            else
            {
                sum1=w1+w2;
                sum2=w2+w3;
                if(sum1<=s || sum2<=s)
                    System.out.println("2");
                else
                    System.out.println("3");
            }
        }
            
    }
}
