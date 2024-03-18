#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp> 
using namespace __gnu_pbds; 
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
struct card
{
  string s;
  int v;
  char suit;
  card(string s)
  {
    this->s = s;
    if(s[0]=='A') v = 14;
    else if(s[0]=='K') v = 13;
    else if(s[0]=='Q') v = 12;
    else if(s[0]=='J') v = 11;
    else if(s[0]=='T') v = 10;
    else v = s[0]-'0';
    suit = s[1];
  }
  bool operator<(const card& o) const
  {
    return v<o.v;
  }
};
ll INF = numeric_limits<ll>::max();

vector<card> one;
vector<card> two;
int dbg = 0;
void printCards()
{
  rep(i,0,5) cout << one[i].s << " ";
  cout << endl;
  rep(i,0,5) cout << two[i].s << " ";
  cout << endl << endl;
}
int tiebreaker()
{
  repn(i,4,-1)
  {
    if(one[i]<two[i]) return 2;
    if(two[i]<one[i]) return 1;
  }
  return 0;
}
int four(vector<card> &cards)
{
  rep(i,3,5) if(cards[i].v==cards[i-1].v&&cards[i].v==cards[i-2].v&&cards[i].v==cards[i-3].v) return cards[i].v;
  return 0;
}
int flush(vector<card> &cards)
{
  rep(i,1,5) if(cards[i].suit!=cards[i-1].suit) return 0;
  return 1;
}
int straight(vector<card> &cards)
{
  rep(i,1,5)
  {
    if(i==4&&cards[3].v==5&&cards[4].v==14) return 5;
    if(cards[i].v!=cards[i-1].v+1) return 0;
  }
  return cards[4].v;
}
int three(vector<card> &cards)
{
  rep(i,2,5) if(cards[i].v==cards[i-1].v&&cards[i].v==cards[i-2].v) return cards[i].v;
  return 0;
}
int fh(vector<card> &cards)
{
  if(cards[0].v==cards[1].v&&three(cards)==cards[4].v) return three(cards);
  if(cards[3].v==cards[4].v&&three(cards)==cards[0].v) return three(cards);
  return 0;
}
int tp(vector<card> &cards)
{
  int pairs = 0;
  int val = -1;
  rep(i,1,5)
  {
    if(cards[i].v==cards[i-1].v)
    {
      pairs++;
      val = cards[i].v;
    }
  }
  if(pairs<2) return 0;
  return val;
}
int p(vector<card> &cards)
{
  rep(i,1,5) if(cards[i].v==cards[i-1].v) return cards[i].v;
  return 0;
}
int score()
{
  if(straight(one)&&flush(one))
  {
    if(straight(two)&&flush(two)) return (straight(one)>straight(two)) ? 1 : 2;
    return 1;
  }
  if(straight(two)&&flush(two)) return 2;
  if(four(one))
  {
    if(four(two))
    {
      if(four(one)==four(two)) return tiebreaker();
      return (four(one)>four(two)) ? 1 : 2;
    }
    return 1;
  }
  if(four(two)) return 2;
  if(fh(one))
  {
    if(fh(two)) return (fh(one)>fh(two)) ? 1 : 2;
    return 1;
  }
  if(fh(two)) return 2;
  if(flush(one))
  {
    if(flush(two)) return tiebreaker();
    return 1;
  }
  if(flush(two)) return 2;
  if(straight(one))
  {
    if(straight(two)) return tiebreaker();
    return 1;
  }
  if(straight(two)) return 2;
  if(three(one))
  {
    if(three(two)) return (three(one)>three(two)) ? 1 : 2;
    return 1;
  }
  if(three(two)) return 2;
  if(tp(one))
  {
    if(tp(two))
    {
      if(tp(one)==tp(two))
      {
        if(p(one)==p(two)) return tiebreaker();
        return (p(one)>p(two)) ? 1 : 2;
      }
      return (tp(one)>tp(two)) ? 1 : 2;
    }
    return 1;
  }
  if(tp(two)) return 2;
  if(p(one))
  {
    if(p(two))
    {
      if(p(one)==p(two)) return tiebreaker();
      return (p(one)>p(two)) ? 1 : 2;
    }
    return 1;
  }
  if(p(two)) return 2;
  return tiebreaker();
}
int f()
{
  one.clear(); two.clear();
  rep(i,0,10)
  {
    string s;
    cin >> s;
    if(i<5) one.pb(card{s});
    else two.pb(card{s});
  }
  sort(all(one)); sort(all(two));
  int sc = score();
  return sc;
}
void solve()
{
  int ans = 0;
  rep(i,0,1000) if(f()==1) ans++;
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