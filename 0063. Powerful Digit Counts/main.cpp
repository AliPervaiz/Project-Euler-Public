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


string add(string a, string b)
{
  if (a.length()>b.length()) swap(a, b); 
  string ret = ""; 
  int n1 = a.length(), n2 = b.length(); 
  int diff = n2 - n1; 
  int c = 0; 
  repn(i,n1-1,-1) 
  { 
    int s = ((a[i]-'0')+(b[i+diff]-'0')+c); 
    ret.push_back(s%10+'0'); 
    c = s/10; 
  }
  repn(i,n2-n1-1,-1)
  { 
    int s = ((b[i]-'0')+c); 
    ret.push_back(s%10+'0'); 
    c = s/10; 
  } 
  if(c) ret.push_back(c+'0'); 
  reverse(ret.begin(), ret.end()); 
  return ret; 
}
string mult(string a, string b)
{
  if (a=="0" || b=="0") return "0";
  int m = a.size() - 1, n = b.size() - 1, c = 0;
  string ret;
  for (int i=0; i<=m+n || c; ++i)
  {
      for(int j=max(0, i-n); j<=min(i, m); ++j) c += (a[m-j] - '0') * (b[n-i+j] - '0');
      ret += c%10+'0';
      c /= 10;
  }
  reverse(all(ret));
  return ret;
}
string spow(string a, int b)
{
  string ret = "1";
  rep(i,0,b) ret = mult(ret,a);
  return ret;
}
void solve()
{
  int ans = 0;
  rep(b,1,10)
  {
    int i = 0;
    //while(++i)
    rep(i,1,100)
    {
      if(i==sz(spow(to_string(b),i))) ans++;
      if(i>sz(spow(to_string(b),i))) break;
    }
  }
  cout << ans << endl;
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