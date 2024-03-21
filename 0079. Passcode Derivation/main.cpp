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

cauto k = 10;
int adj[k][k];
int v[k];
void solve()
{
  rep(t,0,k)
  {
    rep(i,0,k)
    {
      if(!v[i]) continue;
      int prev = 0;
      rep(j,0,k) if(adj[j][i]) prev++;
      if(prev!=0) continue;
      cout << i;
      v[i] = 0;
      rep(j,0,k) adj[i][j] = 0;
    }
  }
  cout << endl;
}
void pre()
{
  freopen("input.txt", "r", stdin);
  int lines = 50;
  rep(i,0,lines)
  {
    string s;
    cin >> s;
    rep(i,0,sz(s)-1) adj[s[i]-'0'][s[i+1]-'0'] = 1;
    rep(i,0,sz(s)) v[s[i]-'0'] = 1;
  }
}
int32_t main() 
{
  pre();
  solve();
}