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
ll MOD = 1e10;
ll INF = numeric_limits<ll>::max();


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
    if(y&1) res=modMult(res,x); 
    y = y>>1; x=modMult(x,x); 
  } 
  return res; 
}
void solve()
{
  cout << modMult(28433,modPow(2,7830457))+1 << endl;
}
void pre()
{
}
int32_t main() 
{
  pre();
  solve();
}