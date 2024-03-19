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
string f2(vi &v)
{
  string n = "1";
  string d = to_string(v[sz(v)-1]);
  repn(i,sz(v)-2,0)
  {
    rep(j,0,v[i]) n = add(n,d);
    string t = n;
    n = d;
    d = t;
  }
  n = add(n,mult(d,to_string(v[0])));
  return n;
}
string f(int x)
{
  int a0 = sqrt(x);
  int n = 1;
  int d = -a0;
  int a = a0;
  set<tuple<int,int,int>> f;
  int i = 0;
  vi v;
  while(true)
  {
    v.pb(a);
    int n2 = -d;
    int d2 = (x - d*d)/n;
    int nexta = floor((sqrt(x)+n2)/d2);
    n2 -= d2*nexta;
    a = nexta;
    n = d2;
    d = n2;
    tuple<int,int,int> t(a,n,d);
    if(f.find(t)!=f.end())
    {
      int csize = sz(v)-1;
      if(i&1) rep(j,1,csize) v.pb(v[j]);
      else v.pop_back();
      return f2(v);
    }
    f.insert(t);
    i++;
  }
}
int square(int n)
{
  int d = sqrt(n);
  return d*d==n;
}
int sgreater(string a, string b)
{
  if(sz(a)>sz(b)) return 1;
  if(sz(b)>sz(a)) return 0;
  rep(i,0,sz(a))
  {
    if(a[i]>b[i]) return 1;
    if(b[i]>a[i]) return 0;
  }
  return 0;
}
void solve()
{
  int k = 1001;
  string biggestX = "0";
  int ans = -1;
  rep(i,2,k+1)
  {
    if(square(i)) continue;
    string x = f(i);
    if(sgreater(x,biggestX))
    {
      biggestX = x;
      ans = i;
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