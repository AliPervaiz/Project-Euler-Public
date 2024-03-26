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

void solve()
{
  ll MAXL = 1000000000;
  ll n = 1;
  ll ans = 0;
  while(true)
  {
    ll m = n;
    while(3*(m*m+m*n)-2<=MAXL)
    {
      while(n%2==m%2||gcd(n,m)!=1) m++;
      ll a = m*m-n*n;
      ll b = 2*m*n;
      ll c = m*m+n*n;
      ll sum = a+b+c;
      int d = c;
      int e1 = 2*a;
      int e2 = 2*b;
      while((d+d+e1)<MAXL||(d+d+e2)<MAXL)
      {
        if(abs(d-e1)==1) ans += d+d+e1;
        if(abs(d-e2)==1) ans += d+d+e2;
        d += c;
        e1 += 2*a;
        e2 += 2*b;
      }
      m++;
    }
    n++;
    m = 1;
    if(2*(m*m+m*n)>MAXL) break;
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