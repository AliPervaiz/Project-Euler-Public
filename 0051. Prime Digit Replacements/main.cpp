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
ll INF = numeric_limits<int>::max();

map<string,int> families;
map<string,int> lowest;
int k;
int ans = INF;
int p(int n)
{
  if(n<2) return 0;
  rep(i,2,sqrt(n)+.0001) if(n%i==0) return 0;
  return 1;
}
void f(int n)
{
  if(!p(n)) return;
  string ns = to_string(n);
  rep(bit,0,1<<sz(ns))
  {
    set<int> s;
    set<int> indices;
    int t = bit;
    rep(i,0,sz(ns))
    {
      if(t&1)
      {
        s.insert(ns[i]-'0');
        indices.insert(i);
      }
      t>>=1;
    }
    if(sz(s)==1)
    {
      string fam = "";
      rep(i,0,sz(ns))
      {
        if(indices.find(i)==indices.end()) fam += ns[i];
        else fam += "*";
      }
      if(families.find(fam)==families.end()) lowest[fam] = n;
      families[fam]++;
      if(families[fam]==k) ans = min(ans,lowest[fam]);
    } 
  }
}
void solve()
{
  k = 8;
  int i = 1;
  int up = 1;
  while(ans==INF)
  {
    up *= 10;
    while(i<up) f(i++);
  }
  cout << ans;
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