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
ll INF = numeric_limits<int>::max();
double EPS = numeric_limits<double>::epsilon();

cauto n = 1000000;
int g[n];
int v[n];

int f(int n)
{
  int sum = 0;
  rep(i,1,sqrt(n)+EPS)
  {
    if(n%i!=0) continue;
    sum += i;
    if(i!=1&&i*i!=n) sum += n/i; 
  }
  return sum;
}
void solve()
{
  int longestLength = 0;
  int ans = 0;
  rep(i,1,n)
  {
    if(v[i]) continue;
    map<int,int> m;
    vi val;
    m[i] = 0;
    v[i] = 1;
    val.pb(i);
    int j = g[i];
    int l = 1;
    while(!v[j])
    {
      v[j] = 1;
      m[j] = l++;
      val.pb(j);
      j = g[j];
    }
    if(m.find(j)!=m.end())
    {
      int length = l-m[j];
      if(length>longestLength)
      {
        longestLength = length;
        ans = INF;
        rep(k,m[j],sz(val)) ans = min(ans,val[k]);
      }
    }
  }
  cout << ans << endl;
}
void pre()
{
  rep(i,1,n)
  {
    int j = f(i);
    if(j<n) g[i] = j;
  }
}
int32_t main() 
{
  pre();
  solve();
}