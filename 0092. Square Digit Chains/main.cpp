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

cauto MAXN = 10000000;
int dp[MAXN];

int f(int n)
{
  if(dp[n]) return dp[n];
  int sum = 0;
  int t = n;
  while(t>0)
  {
    sum += (t%10) * (t%10);
    t /= 10;
  }
  return dp[n] = f(sum);
}
void solve()
{
  int ans = 0;
  rep(i,1,MAXN) if(f(i)==89) ans++;
  cout << ans << endl;
}
void pre()
{
  dp[1] = 1;
  dp[89] = 89;
}
int32_t main() 
{
  pre();
  solve();
}