#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
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

int feq(int n, int d, int n2, int d2)
{
  return n*d2==d*n2;
}
int f(int n, int d)
{
  if(n%10+d%10==0) return 0;
  int ret = 0;
  ret |= feq(n,d,n%10,d%10)&&n/10==d/10;
  ret |= feq(n,d,n/10,d%10)&&n%10==d/10;
  ret |= feq(n,d,n%10,d/10)&&n/10==d%10;
  ret |= feq(n,d,n/10,d/10)&&n%10==d%10;
  return ret;
}
int lden(int n, int d)
{
  repn(i,n,-1) if(n%i==0&&d%i==0) return d/i;
  return d;
}
void solve()
{
  int ansn = 1;
  int ansd = 1;
  rep(n,10,100)
  {
    rep(d,n+1,100)
    {
      if(f(n,d))
      {
        ansn *= n;
        ansd *= d;
      }
    }
  }
  cout << lden(ansn,ansd);
}
void pre()
{
  //freopen("input.txt", "r", stdin);
}
int32_t main() 
{
  pre();
  solve();
}