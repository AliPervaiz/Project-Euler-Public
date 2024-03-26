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

set<int> s;
int nonzero(pii a)
{
  return a.first!=0;
}
pii add(pii a, pii b)
{
  int n = a.first*b.second+b.first*a.second;
  int d = a.second*b.second;
  int div = gcd(n,d);
  return mp(n/div,d/div);
}
pii sub(pii a, pii b)
{
  int n = a.first*b.second-b.first*a.second;
  int d = a.second*b.second;
  int div = gcd(n,d);
  return mp(n/div,d/div);
}
pii mult(pii a, pii b)
{
  int n = a.first*b.first;
  int d = a.second*b.second;
  int div = gcd(n,d);
  return mp(n/div,d/div);
}
pii div(pii a, pii b)
{
  int n = a.first*b.second;
  int d = a.second*b.first;
  int div = gcd(n,d);
  return mp(n/div,d/div);
}
vpii fracs;
void printfracs()
{
  trav(f, fracs) cout << f.first << "/" << f.second << " ";
  cout << endl;
}
void f()
{
  if(sz(fracs)==1)
  {
    if(fracs[0].first%fracs[0].second==0) s.insert(fracs[0].first/fracs[0].second);
    return;
  }
  rep(i,0,sz(fracs))
  {
    rep(j,0,sz(fracs))
    {
      if(i==j) continue;
      vpii origin;
      trav(k, fracs) origin.pb(k);
      fracs.clear();
      rep(k,0,sz(origin)) if(k!=i&&k!=j) fracs.pb(origin[k]);
      fracs.pb(add(origin[i],origin[j]));
      f();
      fracs.pop_back();
      fracs.pb(sub(origin[i],origin[j]));
      f();
      fracs.pop_back();
      fracs.pb(mult(origin[i],origin[j]));
      f();
      fracs.pop_back();
      if(nonzero(origin[j]))
      {
        fracs.pb(div(origin[i],origin[j]));
        f();
        fracs.pop_back();
      }
      fracs.clear();
      trav(k, origin) fracs.pb(k);
    }
  }
}
int score(int a, int b, int c, int d)
{
  s.clear();
  fracs.clear();
  fracs.pb(mp(a,1));
  fracs.pb(mp(b,1));
  fracs.pb(mp(c,1));
  fracs.pb(mp(d,1));
  f();
  int i = 1;
  while(s.find(i)!=s.end()) i++;
  return i;
}
void solve()
{
  int best = 0;
  int ans = 0;
  rep(a,1,10)
  {
    rep(b,a,10)
    {
      rep(c,b,10)
      {
        rep(d,c,10)
        {
          int sc = score(a,b,c,d);
          if(sc>best)
          {
            best = sc;
            ans = a*1000+b*100+c*10+d;
          }
        }
      }
    }
  }
  cout << ans << endl;
}
void pre()
{

}
int32_t main() 
{
  pre();
  solve();
}