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

int c = 0;
vi d1;
vi d2;

int d1c(int x)
{
  trav(i,d1) if(i==x) return 1;
  return 0;
}
int d2c(int x)
{
  trav(i,d2) if(i==x) return 1;
  return 0;
}
int cPair(int a, int b)
{
  return d1c(a)&&d2c(b)||d1c(b)&&d2c(a);
}
int valid()
{
  if(!cPair(0,1)) return 0;
  if(!cPair(0,4)) return 0;
  if(!cPair(0,6)&&!cPair(0,9)) return 0;
  if(!cPair(1,6)&&!cPair(1,9)) return 0;
  if(!cPair(2,5)) return 0;
  if(!cPair(3,6)&&!cPair(3,9)) return 0;
  if(!cPair(4,6)&&!cPair(4,9)) return 0;
  if(!cPair(6,4)&&!cPair(9,4)) return 0;
  if(!cPair(8,1)) return 0;
  return 1;
}
void r(int l)
{
  if(l>9) return;
  if(sz(d1)!=6)
  {
    rep(i,max(0,l),10)
    {
      d1.pb(i);
      if(sz(d1)==6) r(0);
      else r(i+1);
      d1.pop_back();
    }
  }
  else
  {
    rep(i,max(0,l),10)
    {
      d2.pb(i);
      if(sz(d2)==6&&valid()) c++;
      else r(i+1);
      d2.pop_back();
    }
  }
}
void solve()
{
  r(0);
  cout << c/2 << endl;
}
void pre()
{
}
int32_t main() 
{
  pre();
  solve();
}