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
ll INF = numeric_limits<int>::max();

struct node
{
  int r;
  int c;
  int d;
  bool operator<(const node& o) const
  {
    return d>o.d;
  }
};

cauto N = 80;
int m[N][N];
int dist[N][N];
int dr[] = {1,-1,0,0};
int dc[] = {0,0,1,-1};

void solve()
{
  rep(i,0,N) rep(j,0,N) dist[i][j] = INF;
  dist[0][0] = m[0][0];
  priority_queue<node> pq;
  pq.push(node{0,0,dist[0][0]});
  while(!pq.empty())
  {
    node nod = pq.top();
    pq.pop();
    if(nod.d>dist[nod.r][nod.c]) continue;
    rep(i,0,sz(dr))
    {
      int r2 = nod.r + dr[i];
      int c2 = nod.c + dc[i];
      if(r2<0||c2<0||r2>=N||c2>=N) continue;
      if(nod.d+m[r2][c2]>=dist[r2][c2]) continue;
      dist[r2][c2] = nod.d+m[r2][c2];
      pq.push(node{r2,c2,dist[r2][c2]});
    }
  }
  cout << dist[N-1][N-1] << endl;
}
void pre()
{
  freopen("input.txt", "r", stdin);
  int in = 0;
  rep(i,0,N)
  {
    string s;
    cin >> s;
    int curr = 0;
    rep(i,0,sz(s))
    {
      if(s[i]==',')
      {
        m[in/N][in%N] = curr;
        curr = 0;
        in++;
      }
      else curr = curr*10 + s[i]-'0';
    }
    m[in/N][in%N] = curr;
    in++;
  }
}
int32_t main() 
{
  pre();
  solve();
}