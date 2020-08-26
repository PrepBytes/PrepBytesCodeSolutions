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
#define debug(...) fprintf(stderr, _VA_ARGS_), fflush(stderr)
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
ll const N=100005;
vector<set<ll>>adj(N);
struct pt {
    double x, y;
};

bool cmp(pt a, pt b) {
    return a.x < b.x || (a.x == b.x && a.y < b.y);
}

bool cw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) < 0;
}

bool ccw(pt a, pt b, pt c) {
    return a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y) > 0;
}

vector<pt> convex_hull(vector<pt>& a) {
    if (a.size() == 1){
        a.pop_back();
        return a;
    }

    sort(a.begin(), a.end(), &cmp);
    pt p1 = a[0], p2 = a.back();
    vector<pt> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (int i = 1; i < (int)a.size(); i++) {
        if (i == a.size() - 1 || cw(p1, a[i], p2)) {
            while (up.size() >= 2 && !cw(up[up.size()-2], up[up.size()-1], a[i]))
                up.pop_back();
            up.push_back(a[i]);
        }
        if (i == a.size() - 1 || ccw(p1, a[i], p2)) {
            while(down.size() >= 2 && !ccw(down[down.size()-2], down[down.size()-1], a[i]))
                down.pop_back();
            down.push_back(a[i]);
        }
    }

    a.clear();
    for (int i = 0; i < (int)up.size(); i++)
        a.push_back(up[i]);
    for (int i = down.size() - 2; i > 0; i--)
        a.push_back(down[i]);
    return a;
}
vvi g;
vi vvv;
void dfs(vvi &adj1,vb &vis,ll node){
    vvv.pb(node);
    vis[node]=true;
    for(auto i:adj1[node]){
        if(!vis[i])dfs(adj1,vis,i);
    }
}
vector<ll>P,R;
void create_set(ll x){
    P[x]=x;
    R[x]=0;
}
ll find_set(ll x){
    if(x!=P[x])P[x]=find_set(P[x]);
    return P[x];
}
void merge_set(ll x,ll y){
    x=find_set(x);
    y=find_set(y);
    if(x==y)return ;
    if(R[x]<R[y])swap(x,y);
    P[y]=x;
    if(R[x]==R[y])R[x]++;
}
struct Edges{
    ll u,v,weight;
    bool operator<(Edges const& other){
        return weight<other.weight;
    }
};
void solve(){
    ll n,m,p;
    cin>>n>>m;
    map<pair<double,double>,ll>mp;
    vpii v(m+5);
    for(int i=0;i<m;i++){
        ll x,y;
        cin>>x>>y;
        v[i]={x,y};
        adj[x].insert(y);
        adj[y].insert(x);
    }
    vector<pt>a(n+5);
    for(ll i=0;i<n;i++){
        cin>>a[i].x>>a[i].y;
        double l1=a[i].x;
        double l2=a[i].y;
        mp[{l1,l2}]=i+1;

    }
    cin>>p;
    vector<pt>b=convex_hull(a);
    map<ll,ll>mp1;
    for(auto it:b){
        double l1=it.x;
        double l2=it.y;
        mp1[mp[{l1,l2}]]++;
    }
    vector<pii>border;
    vector<pii>not_border;
    bool f=false;
    for(auto i:v){
        if(!mp1[i.fi] and mp1[i.se]){
            f=true;
            continue;
        }
        else if(mp1[i.fi] and !mp1[i.se]){
            f=true;
            continue;
        }
        else if(mp1[i.fi] and mp1[i.se])border.pb(i);
        else not_border.pb(i);
    }
    map<ll,ll>mp2;
    ll cnt=1;
    vpii v1;
    for(auto i:not_border){
        ll x=mp2[i.fi],y=mp2[i.se];
        if(!mp2[i.fi]){
            x=cnt;
            mp2[i.fi]=cnt;
            cnt++;
        }
        if(!mp2[i.se]){
            y=cnt;
            mp2[i.se]=cnt;
            cnt++;
        }
        v1.pb({x,y});
    }
    vvi adj1(cnt);
    for(auto i:v1){
        adj1[i.fi].pb(i.se);
        adj1[i.se].pb(i.fi);
    }
    vb vis(cnt,false);
    for(int i=1;i<cnt;i++){
        if(!vis[i]){
            vvv.clear();
            dfs(adj1,vis,i);
            if(sz(vvv))g.pb(vvv);
        }
    }
    vi extraa;
    for(auto i:g){
        extraa.pb(i[0]);
    }
    for(int i=1;i<sz(extraa);i++){
        v1.pb({extraa[i-1],extraa[i]});
    }
    ll ans=0;
    if(sz(extraa)>=2)ans=sz(extraa)-1;
    vector<Edges>edges,result;
    P.resize(cnt+5);
    R.resize(cnt+5);
    for(int i=1;i<cnt;i++)create_set(i);
    for(int i=0;i<sz(v1);i++){
        ll a,b,c;
        a=v1[i].fi;
        b=v1[i].se;
        c=1;
        edges.push_back({a,b,c});
    }
    sort(edges.begin(),edges.end());
    for(Edges e:edges){
        if(find_set(e.u)!=find_set(e.v)){
            ans+=e.weight;
            merge_set(e.u,e.v);
            result.push_back(e);
        }
    }
    if(!f)ans+=p;
    cout<<sz(b)<<" "<<ans<<"\n";
    vi fin;
    for(auto i:b)fin.pb(mp[{i.x,i.y}]);
    sort(all(fin));
    for(auto i:fin)cout<<i<<" ";
}
int main(){

    fio;

    ll t;
    t=1;
    // cin>>t;
    // cout<<t<<"\n";
    while(t--){
        solve();
    }

   return 0;
}
