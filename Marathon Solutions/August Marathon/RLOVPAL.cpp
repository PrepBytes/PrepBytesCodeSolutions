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
    void solve(){
        ll n;
        cin>>n;
        ll ans=0;
        for(int i=0;i<n;i++){
            string s;
            cin>>s;
            int a[26]={0};
            for(auto j:s)a[j-'a']++;
            bool f=true;
            int cnt=0;
            for(int j=0;j<26;j++){
                if(a[j]&1 and cnt>=1){
                    f=false;
                }
                else if(a[j]&1){
                    cnt++;
                }
            }
            if(f)ans++;
        }
        cout<<ans<<"\n";
    }
int main(){
    
    fio;
    clock_t zzzz = clock();
    ll T;
    T=1;
    cin>>T;
    while(T--){
        solve();
    }
    //debug("Total Time: %.3f\n", (double)(clock() - zzzz) / CLOCKS_PER_SEC);
   return 0;
}
