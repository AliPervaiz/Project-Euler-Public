#include <bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)

#define rep(i,a,b) for(auto i=(a); i<(b); ++i)
#define repc(i,a,b,c) for(auto i=(a); i<(b); i+=c)
#define repn(i,a,b) for(auto i=(a); i>(b); --i)
#define trav(a,x) for(auto& a: x)
#define travm(a,x) for(const auto& [a, v]: x)
#define all(x) begin(x),end(x)
#define sz(x) (int)size(x)
#define madd(a,b) (a+b)%MOD
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
ll INF = numeric_limits<ll>::max();
double EPS = numeric_limits<double>::epsilon();

ll f(ll i)
{
  return i*i-i;
}
int valid(ll n, ll d)
{
  return 2*n*(n-1)==d*(d-1);
}
void solve()
{
  ll mi = 1000000000000;
  ll bestD = mi*10;
  ll ans;
  rep(d,(ll)1,(ll)10000000)
  {
    ll n = round(d*.707106591);
    ll l = mi/d;
    ll r = bestD/d;
    while(l<r)
    {
      ll m = (l+r)/2;
      ll n2 = n*m;
      ll d2 = d*m;
      if(2*n2*(n2-1)>d2*(d2-1)) r = m-1;
      else if(2*n2*(n2-1)<d2*(d2-1)) l = m+1;
      else l = r = m;
    }
    if(d*l<mi||d*l>bestD) continue;
    if(valid(n*l,d*l))
    {
      bestD = d*l;
      ans = n*l;
    }
  }
  cout << ans << endl;
}
void pre()
{
  
}
int32_t main() 
{
  pre();
  solve();
}