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
int k = 100;

string sMult(string a, string b)
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
int sGreater(string a, string b)
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
int dSum(string n)
{
  int sum = 0;
  rep(i,0,k) sum += n[i]-'0';
  return sum;
}
int root(int n)
{
  string prod = to_string(n);
  rep(i,0,2*k) prod += "0";
  string cand = "1";
  rep(i,0,k) cand += "0";
  rep(i,0,sz(cand))
  {
    cand[i] = '1';
    while(sGreater(prod,sMult(cand,cand))&&cand[i]!='9') cand[i]++;
    if(sGreater(sMult(cand,cand),prod)) cand[i]--;
  }
  return dSum(cand);
}
int square(int n)
{
  int d = sqrt(n);
  return d*d==n;
}
void solve()
{
  int ans = 0;
  rep(i,1,101) if(!square(i)) ans += root(i);
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