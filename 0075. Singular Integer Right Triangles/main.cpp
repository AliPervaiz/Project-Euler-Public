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

void solve()
{
  ll MAXL = 1500000;
  ll n = 1;
  ll count = 0;
  map<ll,int> f;
  while(true)
  {
    ll m = n;
    while(2*(m*m+m*n)<=MAXL)
    {
      while(n%2==m%2||gcd(n,m)!=1) m++;
      ll a = m*m-n*n;
      ll b = 2*m*n;
      ll c = m*m+n*n;
      ll sum = a+b+c;
      ll times = MAXL/(a+b+c);
      rep(i,1,times+1)
      {
        ll L = (a+b+c)*i;
        f[L]++;
        if(f[L]==1) count++;
        else if(f[L]==2) count--;
      }
      m++;
    }
    n++;
    m = 1;
    if(2*(m*m+m*n)>MAXL) break;
  }
  cout << count << endl;
}
void pre()
{
  
}
int32_t main() 
{
  pre();
  solve();
}