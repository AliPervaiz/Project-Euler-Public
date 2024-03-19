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

ll modMult(ll x, ll y)
{
    ll res = 0;
    x%=MOD;
    while(y>0)
    {
        if(y&1) res=(res+x)%MOD;
        x=(x*2)%MOD;
        y>>=1;
    }
    return res%MOD;
}
ll modPow(ll x, ll y) 
{ 
    ll res = 1; x %= MOD;
    if(x==0) return 0;
    while(y>0) 
    { 
        if(y&1) res=mm(res,x); 
        y = y>>1; x=mm(x,x); 
    } 
    return res; 
} 
int aOvf(ll a, ll b)
{ 
  ll temp; 
  return __builtin_add_overflow(a,b,&temp);
}
int mOvf(ll a, ll b)
{
  ll temp; 
  return __builtin_mul_overflow(a,b,&temp);
}

auto stopwatch_tick() {
  return chrono::high_resolution_clock::now();
}
 
auto stopwatch_duration(auto st, auto en) {
  return chrono::duration_cast<chrono::milliseconds>(en - st).count();
}
struct node
{
  ll l;
  ll r;
  // bool operator<(const node& o) const
  // {
  //   return l>o.l;
  // }
};
ll INF = numeric_limits<ll>::max();

vector<vi> sets;
vi curr;
int c[11];
int cantBeTen[] = {1,2,4,6,8};
int cand[] = {9,8,7,6,5,4,3,2,1,10};
int external[] = {3,5,7,9};
int done;
int check()
{
  trav(i,cantBeTen) if(i<sz(curr)&&curr[i]==10) return 0;
  trav(i,external) if(i<sz(curr)&&curr[i]<curr[0]) return 0;
  set<int> sums;
  rep(i,0,sz(sets))
  {
    int sum = 0;
    bool valid = true;
    trav(j,sets[i])
    {
      if(j>=sz(curr)) valid = false;
      else sum += curr[j];
    }
    if(valid) sums.insert(sum);
  }
  return sz(sums)<=1;
}
void printAns()
{
  rep(i,0,sz(sets))
  {
    trav(j,sets[i]) cout << curr[j];
  }
  cout << endl;
}
void f(int n)
{
  if(done) return;
  curr.pb(n);
  c[n] = 1;
  if(check())
  {
    if(sz(curr)==10)
    {
      done = 1;
      printAns();
    }
    trav(i,cand) if(!c[i]) f(i);
  }
  c[n] = 0;
  curr.pop_back();
}
void solve()
{
  trav(i,cand) f(i);
}
void pre()
{
  //freopen("input.txt", "r", stdin);
  sets.pb({0,1,2});
  sets.pb({3,2,4});
  sets.pb({5,4,6});
  sets.pb({7,6,8});
  sets.pb({9,8,1});
}
int32_t main() 
{
  pre();
  solve();
}