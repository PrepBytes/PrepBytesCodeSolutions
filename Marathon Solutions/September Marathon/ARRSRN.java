import java.util.*;

 class solution{

    void solve() {
        final int N = 505;
        int[] a = new int[N];
        int[][] dp = new int[N][N];
        int[] dp2 = new int[N];
        Scanner in = new Scanner(System.in);
        int n;
        n = in.nextInt();
        in.nextLine();

        for (int i=1; i<=n; i++) {
            a[i] = in.nextInt();
            dp[i][i] = a[i];
        }

        for (int len=2; len<=n; len++) {
            for (int l=1; l+len-1<=n; l++) {
                int r = l+len-1;
                for (int i=l; i<r; i++) {
                    if (dp[l][i] > 0  && dp[i+1][r] > 0 && dp[l][i] == dp[i+1][r])
                        dp[l][r] = dp[l][i]+1;
                }
            }
        }

        dp2[0] = 0;
        for (int i=1; i<=n; i++) {
            dp2[i] = n;
            for (int j=i; j>0; j--)
                if (dp[j][i] != 0)
                    dp2[i] = Math.min(dp2[i], dp2[j-1]+1);
        }
        System.out.println(dp2[n]);
    }

    public static void main(String []args){
        (new solution()).solve();
    }
}
