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

cauto tc = 50;
cauto n = 9;
int board[n][n];
bool found;
int ans = 0;

int val(int r, int c, int v)
{
  rep(c2,0,n) if(c2!=c&&board[r][c2]==v) return 0;
  rep(r2,0,n) if(r2!=r&&board[r2][c]==v) return 0;
  rep(r2,r/3*3,r/3*3+3) rep(c2,c/3*3,c/3*3+3) if((r2!=r||c2!=c)&&board[r2][c2]==v) return 0;
  return 1;
}
void f(int i)
{
  if(found) return;
  if(i==n*n)
  {
    found = true;
    ans += 100*board[0][0] + 10*board[0][1] + board[0][2];
  }
  int r = i/n;
  int c = i%n;
  if(board[r][c])
  {
    f(i+1);
    return;
  }
  else
  {
    rep(v,1,n+1)
    {
      if(val(r,c,v))
      {
        board[r][c] = v;
        f(i+1);
        board[r][c] = 0;
      }
    }
  }
}
void solve()
{
  rep(t,0,tc)
  {
    found = false;
    string ex, ex2;
    cin >> ex >> ex2;
    rep(i,0,n)
    {
      string s;
      cin >> s;
      rep(j,0,n) board[i][j] = s[j]-'0';
    }
    f(0);
  }
  cout << ans << endl;
}
void pre()
{
  freopen("input.txt", "r", stdin);
}
int32_t main() 
{
  pre();
  solve();
}