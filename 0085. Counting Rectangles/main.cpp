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

cauto maxn = 100;
int dp[maxn][maxn];
int f(int r, int c)
{
  if(r<1||c<1) return 0;
  if(dp[r][c]!=-1) return dp[r][c];
  return dp[r][c] = r*c+f(r-1,c)+f(r,c-1)-f(r-1,c-1);
}
void solve()
{
  int k = 2000000;
  int closestF = 0;
  int ans = 0;
  rep(h,1,maxn)
  {
    rep(w,1,h+1)
    {
      int cf = f(h,w);
      if(abs(cf-k)<abs(closestF-k))
      {
        closestF = cf;
        ans = h*w;
      }
    }
  }
  cout << ans << endl;
}
void pre()
{
  rep(i,0,maxn) rep(j,0,maxn) dp[i][j] = -1;
  dp[1][1] = 1;
}
int32_t main() 
{
  pre();
  solve();
}