#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define repc(i,a,b,c) for(auto i=(a); i<(b); i+=c)
#define repn(i,a,b) for(auto i=(a); i>(b); --i)
#define trav(a,x) for(auto& a: x)
#define travm(a,x) for(const auto& [a, v]: x)
#define all(x) begin(x),end(x)
#define sz(x) (int)size(x)
#define madd(a,b) (a+b)%MOD
#define mm(a,b) ((ll)a*b)%MOD
#define tmod(a,b) ((a%b)+b)%b
#define pb push_back
#define mp make_pair
#define cauto const auto
using ll = long long;
using ld = long double;
using pii = pair<int,int>;
using pll = pair<ll,ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;

ll MOD = 1e9+7;

ll modMult(ll x, ll y)
{
    ll res = 0;
    x%=MOD;
    while(y>0)
    {
        if(y&1) res=(res+x)%MOD;
        x=(x*2)%MOD;
        y>>=1;
    }
    return res%MOD;
}
ll modPow(ll x, ll y) 
{ 
    ll res = 1; x %= MOD;
    if(x==0) return 0;
    while(y>0) 
    { 
        if(y&1) res=mm(res,x); 
        y = y>>1; x=mm(x,x); 
    } 
    return res; 
} 
int aOvf(ll a, ll b)
{ 
  ll temp; 
  return __builtin_add_overflow(a,b,&temp);
}
int mOvf(ll a, ll b)
{
  ll temp; 
  return __builtin_mul_overflow(a,b,&temp);
}

auto stopwatch_tick() {
  return chrono::high_resolution_clock::now();
}
 
auto stopwatch_duration(auto st, auto en) {
  return chrono::duration_cast<chrono::milliseconds>(en - st).count();
}
struct node
{
  ll l;
  ll r;
  // bool operator<(const node& o) const
  // {
  //   return l>o.l;
  // }
};
ll INF = numeric_limits<ll>::max();

cauto MAXN = 10000;
vi P[9];
vi perm = {4,5,6,7,8};
int ans = -1;
int cyclic(int a, int b)
{
  return a%100==b/100&&a!=b;
}
void f(int s, int e, int in, int sum)
{
  trav(cand,P[perm[in]])
  {
    if(!cyclic(e,cand)) continue;
    if(in==sz(perm)-1)
    {
      if(cyclic(cand,s)) ans = sum+cand;
    }
    else f(s,cand,in+1,sum+cand);
  }
}
void solve()
{
  do
  {
    trav(tri,P[3]) f(tri,tri,0,tri);
  }
  while(next_permutation(all(perm))&&ans==-1);
  cout << ans << endl;
}
void pre()
{
  //freopen("input.txt", "r", stdin);
  int n = 1;
  while(n*(n+1)/2<MAXN)
  {
    if(n*(n+1)/2>=1000) P[3].pb(n*(n+1)/2);
    if(n*n<MAXN&&n*n>=1000) P[4].pb(n*n);
    if(n*(3*n-1)/2<MAXN&&n*(3*n-1)/2>=1000) P[5].pb(n*(3*n-1)/2);
    if(n*(2*n-1)<MAXN&&n*(2*n-1)>=1000) P[6].pb(n*(2*n-1));
    if(n*(5*n-3)/2<MAXN&&n*(5*n-3)/2>=1000) P[7].pb(n*(5*n-3)/2);
    if(n*(3*n-2)<MAXN&&n*(3*n-2)>=1000) P[8].pb(n*(3*n-2));
    n++;
  }
}
int32_t main() 
{
  pre();
  solve();
}