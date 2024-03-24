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
  int n;
  int s;
  int p;
  bool operator<(const node& o) const
  {
    return p>o.p;
  }
};
cauto maxn = 12000;
int k[maxn+1]; 
set<tuple<int,int,int>> v;
void solve()
{
  priority_queue<node> pq;
  pq.push(node{1,1,1});
  while(!pq.empty())
  {
    node nod = pq.top();
    pq.pop();
    int c = 2;
    while(nod.p*c<=2*maxn)
    {
      int tempK = (nod.p*c)-(nod.s+c)+(nod.n+1);
      if(tempK>maxn) break;
      tuple<int,int,int> temp = make_tuple(nod.n+1,nod.s+c,nod.p*c);
      if(v.find(temp)==v.end())
      {
        pq.push(node{nod.n+1,nod.s+c,nod.p*c});
        v.insert(temp);
      }
      if(nod.p*c<k[tempK]) k[tempK] = nod.p*c;
      c++;
    }
  }
  set<int> ks;
  rep(i,2,maxn+1) ks.insert(k[i]);
  int ans = 0;
  trav(i,ks) ans += i;
  cout << ans << endl;
}
void pre()
{
  rep(i,0,maxn+1) k[i] = INF;
}
int32_t main() 
{
  pre();
  solve();
}