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
cauto MAXN = 8000;
cauto MAXK = 50000000;
int sieve[MAXN];
vi two;
vi three;
vi four;
void solve()
{
  set<int> s;
  trav(a,two) trav(b,three) trav(c,four) if(a+b+c<MAXK) s.insert(a+b+c);
  cout << sz(s) << endl;
}
void pre()
{
  rep(i,2,MAXN) sieve[i] = 1;
  rep(i,2,MAXN)
  {
    if(!sieve[i]) continue;
    repc(j,i*2,MAXN,i) sieve[j] = 0;
    if((ll)i*i<MAXK) two.pb(i*i);
    if((ll)i*i*i<MAXK) three.pb(i*i*i);
    if((ll)i*i*i*i<MAXK) four.pb(i*i*i*i);
  }
}
int32_t main() 
{
  pre();
  solve();
}