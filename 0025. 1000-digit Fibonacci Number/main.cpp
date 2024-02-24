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

string add(string a, string b)
{
  stack<int> one;
  stack<int> two;
  stack<int> ans;
  rep(i,0,sz(a)) one.push(a[i]-'0');
  rep(i,0,sz(b)) two.push(b[i]-'0');
  int r = 0;
  while(sz(one)+sz(two)>0)
  {
    int d1 = 0;
    int d2 = 0;
    if(!one.empty())
    {
      d1 = one.top();
      one.pop();
    }
    if(!two.empty())
    {
      d2 = two.top();
      two.pop();
    }
    r += d1 + d2;
    ans.push(r%10);
    r/=10;
  }
  string ret = "";
  if(r!=0) ret = to_string(r);
  while(!ans.empty())
  {
    ret += to_string(ans.top());
    ans.pop();
  }
  return ret;
}
void solve()
{
  string a = "1";
  string b = "1";
  int n = 1000;
  int in = 2;
  while(sz(b)<n)
  {
    string t = b;
    b = add(a,b);
    a = t;
    in++;
  }
  cout << in;
}
void pre()
{
  //freopen("input.txt", "r", stdin);
}
int32_t main() 
{
  pre();
  solve();
}