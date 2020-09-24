#include<bits/stdc++.h>
using namespace std;

const int N = 505;
int a[N];
int dp[N][N];
int dp2[N];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n;

    for (int i=1; i<=n; i++) {
        cin>>a[i];
        dp[i][i] = a[i];
    }

    for (int len=2; len<=n; len++) {
        for (int l=1; l+len-1<=n; l++) {
            int r = l+len-1;
            for (int i=l; i<r; i++) {
                if (dp[l][i] && dp[i+1][r] && dp[l][i] == dp[i+1][r])
                    dp[l][r] = dp[l][i]+1;
            }
        }
    }

    dp2[0] = 0;
    for (int i=1; i<=n; i++) {
        dp2[i] = n;
        for (int j=i; j>0; j--)
            if (dp[j][i])
                dp2[i] = min(dp2[i], dp2[j-1]+1);
    }
    cout<<dp2[n]<<endl;
}
