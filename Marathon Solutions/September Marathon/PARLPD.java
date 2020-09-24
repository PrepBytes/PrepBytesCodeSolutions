/*Parallelopied property
It has three sets of four parallel edges and the edges within each set have equal measurement of length.*/



import java.util.Scanner;

 class PARLPD {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();
        while(t-->0)
        {
            int arr[] = new int[12];
            for(int i=0;i<12;i++)
                arr[i]=sc.nextInt();

            boolean ans=true;
            for(int i=0;i<12;i++)
            {
                int k=0;
                for(int j=0;j<12;j++)
                {
                    if(arr[i]==arr[j])
                        k++;

                }
                if(k%4!=0)
                {
                    ans=false;
                    break;
                }
            }
            if(ans)
                System.out.println("yes");
            else
                System.out.println("no");
        }
    }
}
