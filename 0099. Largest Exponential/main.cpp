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

cauto n = 1000;
int base[n+1];
int ex[n+1];

void solve()
{
  double best = 1;
  int line = -1;
  rep(l,1,n+1)
  {
    if(ex[l]*log(base[l])>best)
    {
      best = ex[l]*log(base[l]);
      line = l;
    }
  }
  cout << line << endl;
}
void pre()
{
  freopen("input.txt", "r", stdin);
  rep(i,1,n+1)
  {
    string s;
    cin >> s;
    int b = 0;
    int e = 0;
    int f = 0;
    rep(i,0,sz(s))
    {
      if(s[i]==',') f = 1;
      else if(f==0) b = b*10+s[i]-'0';
      else e = e*10+s[i]-'0';
    }
    base[i] = b;
    ex[i] = e;
  }
}
int32_t main() 
{
  pre();
  solve();
}