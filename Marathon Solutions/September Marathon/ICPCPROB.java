import java.util.*;

 class solution {
    HashMap<String, Integer> dp = new HashMap<>();
    final long mod=(long)(1e9+7);
    long mul(long a,long b){
        return ((a%mod)*(b%mod))%mod;
    }
    public void solve() {
        Scanner in = new Scanner(System.in);
        long T;
        T=1;
        T = in.nextInt();
        in.nextLine();
        while(T-- > 0){
            String s;
            s = in.nextLine();
            long ans = 1;
            int n = s.length();
            for(long bt = 0; bt < (1 << (n-1)); bt++){
                long cnt = 0;
                for(int i = 0; i < n-1; i++){
                    cnt *= 10;
                    cnt += s.charAt(i) - '0';
                    if((bt & (1 << i)) != 0){
                        ans = mul(ans, cnt);
                        cnt = 0;
                    }
                }
                cnt *= 10;
                cnt += s.charAt(n-1)  - '0';
                ans = mul(ans, cnt);
            }
            System.out.println(ans);
        }
    }

    public static void main(String[] args) {
        (new solution()).solve();
    }
}
