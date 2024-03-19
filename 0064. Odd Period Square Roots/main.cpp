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

int f(int x)
{
  int a0 = sqrt(x);
  int n = 1;
  int d = -a0;
  int a = a0;
  set<tuple<int,int,int>> f;
  int i = 0;
  while(true)
  {
    int n2 = -d;
    int d2 = (x - d*d)/n;
    int nexta = floor((sqrt(x)+n2)/d2);
    n2 -= d2*nexta;
    a = nexta;
    n = d2;
    d = n2;
    tuple<int,int,int> t(a,n,d);
    if(f.find(t)!=f.end()) return i;
    f.insert(t);
    i++;
  }
}
int square(int n)
{
  int d = sqrt(n);
  return d*d==n;
}
void solve()
{
  int k = 10000;
  int ans = 0;
  rep(i,2,k+1) if(!square(i)) if(f(i)&1) ans++;
  cout << ans << endl;
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