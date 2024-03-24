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
ll INF = numeric_limits<ll>::max();

cauto maxm = 2000;

set<tuple<int,int,int>> s;
void f(int a, int b)
{
  if(b<=maxm) rep(i,1,min(b,maxm)+1) if(i<=a-i&&a-i<=b) s.insert(make_tuple(i,a-i,b));
  if(a<=maxm) rep(i,1,min(a,maxm)+1) if(i<=b-i&&b-i<=a) s.insert(make_tuple(i,b-i,a));
}
int a[maxm+1];
void solve()
{
  ll n = 1;
  while(true)
  {
    ll m = n;
    while(true)
    {
      while(n%2==m%2||gcd(n,m)!=1) m++;
      ll a = m*m-n*n;
      ll b = 2*m*n;
      ll c = m*m+n*n;
      if(min(a,b)>maxm) break;
      ll times = maxm/min(a,b);
      rep(i,1,times+1) f(min(a*i,b*i),max(a*i,b*i));
      m++;
    }
    n++;
    if(2*n*n>10*maxm) break;
  }
  trav(t,s) a[max(max(get<0>(t),get<1>(t)),get<2>(t))]++;
  int sum = 0;
  int c = 0;
  while(sum < 1000000) sum += a[++c];
  cout << c << endl;
}
void pre()
{
  
}
int32_t main() 
{
  pre();
  solve();
}