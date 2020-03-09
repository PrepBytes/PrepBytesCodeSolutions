import java.util.Arrays;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        int caseV=1;
        while(t-->0)
        {
            int n=sc.nextInt();
            int p=sc.nextInt();
            int []arr = new int[n];
            for(int i=0;i<n;i++)
                arr[i]=sc.nextInt();
            Arrays.sort(arr);
            int []prefixArray = new int[n+1];
            for(int j=0;j<n;j++){
                prefixArray[j+1] = prefixArray[j]+arr[j];
            }
            long result  = Long.MAX_VALUE;
            for(int j=p-1;j<n;j++)
            {
                long currentSum = prefixArray[j]-prefixArray[j-(p-1)];
                long finalHours = arr[j]*(p-1) - currentSum;
                result = Math.min(result,finalHours);
            }
            System.out.println("Case #"+caseV+": "+result);
            caseV++;
        }
    }
}
