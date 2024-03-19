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

cauto MAXN = 10000000;
ll totient[MAXN+1];
int prime[MAXN+1];
int f(int n)
{
  vi v(10);
  string one = to_string(n);
  string two = to_string(totient[n]);
  rep(i,0,sz(one)) v[one[i]-'0']++;
  rep(i,0,sz(two)) v[two[i]-'0']--;
  rep(i,0,sz(v)) if(v[i]) return 0;
  return 1;
}
void solve()
{
  ll bestN = 10;
  ll bestD = 1;
  rep(i,2,MAXN)
  {
    if(i*bestD<bestN*totient[i]&&f(i))
    {
      bestN = i;
      bestD = totient[i];
    }
  }
  cout << bestN << endl;
}
void pre()
{
  //freopen("input.txt", "r", stdin);
  rep(i,2,sz(prime))
  {
    prime[i] = 1;
    totient[i] = i;
  }
  rep(i,2,sz(prime))
  {
    if(!prime[i]) continue;
    totient[i]--;
    repc(j,i*2,sz(prime),i)
    {
      prime[j] = 0;
      totient[j] = totient[j]*(i-1)/i;
    }
  }
}
int32_t main() 
{
  pre();
  solve();
}