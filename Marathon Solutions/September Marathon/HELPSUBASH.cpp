// Author:: MUKUL KUMAR RAI
// Institution:: Jalpaiguri Government Engineering College
//If you are not doing well now just stick to it and learn new things one day you will be...
//Compete with yourself
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define ld long double
#define fi first
#define se second
#define pb push_back
///*template{{{
#define sz(x) (ll)x.size()
#define all(x) x.begin(),x.end()
#define trav(a,x) for(auto &a:x)
#define fr(i,a,b)  for(ll i=a;i<=b;i++)
#define fr1(i,a)   for(ll i=0;i<a;i++)
#define frr(i,a,b) for(ll i=b;i>=a;i--)
#define frr1(i,a)   for(ll i=a-1;i>=0;i--)
#define sorta(a,n) sort(a,a+n)
#define sortd(a,n) sort(a,a+n,greater<ll>())
#define sorva(a) sort(a.begin(),a.end())
#define sortvd(a) sort(a.begin(),a.end(),greater<ll>())
#define tc(t) while(t--)
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
using vi= vector<ll>;
using vvi= vector<vi>;
using vb =vector<bool>;
using vc =vector<char>;
using vs =vector<string>;
using vld =vector<ld>;
using pii =pair<ll,ll>;
using psi =pair<string,ll>;
using pci =pair<char,ll>;
using vpii =vector<pii>;
//}}}template*/
ll const mod=1e9+7;
ll const maxn=1e5+5;
ll const inf=1e18;
ll add(ll a,ll b){
    return ((a%mod)+(b%mod))%mod;
}
ll mul(ll a,ll b){
    return ((a%mod)*(b%mod))%mod;
}
ll powm(ll x,ll n,ll M)
{
    ll result=1;
    while(n>0)
    {
        if(n % 2 ==1)
            result=(result * x)%M;
        x=(x*x)%M;
        n=n/2;
    }
    return result;
}
ll modinverse(ll a, ll m){
    return powm(a,m-2,m);
}
bool prime(ll x){
    if(x<=1)return false;
    for(int i=2;i<=sqrt(x);i++)if(x%i==0)return false;
    return true;
}
ll divisor(ll x){
    ll cnt=0;
    for(int i=1;i<=sqrt(x);i++){
        if(x%i==0){
            if(i!=x/i)cnt+=2;
            else cnt+=1;
        }
    }
    return cnt;
}
vector<ll> sieve(ll n) {    
    bool prim[n+1];
    memset(prim, true, sizeof(prim));
    for (ll p=2; p*p<=n; p++) {
        if (prim[p] == true) {
            for (int i=p*p; i<=n; i += p)
                prim[i] = false;
        }
    }
    vector<ll>v;
    for(int i=2;i<=n;i++)if(prim[i])v.push_back(i);
    return v;
}
vi v;
vi has(110,0);
ll d;
ll dp[19][50][50][2][2][19];
void pre(){
    vi pp = sieve(100);
    for(auto i : pp){
        if(i < d)
        has[i]++;
    }
}
void init(ll x){
    v.clear();
    while(x){
        v.pb(x % 10);
        x /= 10;
    }
    reverse(all(v));

}
ll fun(ll pos, ll non_p_idx, ll p_idx, ll f, ll start, ll last){
    if(pos == sz(v)){
        // cout << s  <<" "<<non_p_idx <<" "<<p_idx<<'\n';
        // cout << s <<"\n";
        if(has[(non_p_idx * p_idx)%d]){
            return 1;
        }
        return 0;
    }
    ll &res = dp[pos][non_p_idx][p_idx][f][start][last];
    if(res != -1)
        return res;
    res = 0 ;
    ll lmt = 9;
    if(f == 0)
        lmt = v[pos];
    for(int dgt = 0; dgt <= lmt; dgt++){
        ll nf = f;
        if(f == 0 and dgt < lmt)
            nf = 1;
        if(start == 0 and dgt == 0){
            res += fun(pos + 1, non_p_idx, p_idx, nf, start, 0);
            continue;
        }
        ll n_non_p_idx = non_p_idx;
        ll n_p_idx = p_idx;
        if(has[last+1]){
            n_p_idx += dgt;
            n_p_idx %= d;
        }
        else{
            n_non_p_idx += dgt;
            n_non_p_idx %= d;
        }
        res += fun(pos+1, n_non_p_idx, n_p_idx, nf, 1, last + 1);
    }
    return res;
}
ll find_ans(ll x){
    init(x);
    memset(dp, -1, sizeof(dp));
    return fun(0, 0, 0, 0, 0, 0);
}
void solve(){
    ll l, r;
    cin >> l >>r >> d;
    pre();
    cout << find_ans(r) - find_ans(l-1)<<"\n";
}
int main(){
    // #ifndef ONLINE_JUDGE
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    // #endif
    fio;
    clock_t zzzz = clock();
    ll T;
    T=1;
    cin>>T;
    while(T--){
        solve();
    }
    debug("Total Time: %.3f\n", (double)(clock() - zzzz) / CLOCKS_PER_SEC);
   return 0;
}



