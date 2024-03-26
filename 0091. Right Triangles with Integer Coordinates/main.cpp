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

int rT(double a, double b, double c)
{
  vector<double> v = {a,b,c};
  sort(all(v));
  return abs(v[0]*v[0]+v[1]*v[1]-v[2]*v[2])<.001;
}
int f(int x1, int y1, int x2, int y2)
{
  if(x1+y1==0||x2+y2==0||x1+x2==0||y1+y2==0) return 0;
  if(x1==x2&&y1==y2) return 0;
  return rT(sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)),sqrt(x1*x1+y1*y1),sqrt(x2*x2+y2*y2));
}
void solve()
{
  int ans = 0;
  int n = 50;
  rep(x1,0,n+1) rep(y1,0,n+1) rep(x2,0,n+1) rep(y2,0,n+1) ans += f(x1,y1,x2,y2);
  cout << ans/2 << endl;
}
void pre()
{
  
}
int32_t main() 
{
  pre();
  solve();
}