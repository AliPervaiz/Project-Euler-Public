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

map<char,int> rMap = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
int dArr[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000};
string rArr[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};

string d2r(int d)
{
  string rn;
  repn(i,sz(dArr)-1,-1)
  {
    rep(j,0,d/dArr[i]) rn += rArr[i];
    d %= dArr[i];
  }
  return rn;
}
int r2d(string rn)
{
  int d = 0;
  rep(i,0,sz(rn))
  {
    if(i<sz(rn)-1&&rMap[rn[i+1]]>rMap[rn[i]]) d += rMap[rn[i+1]] - rMap[rn[i++]];
    else d += rMap[rn[i]];
  }
  return d;
}
void solve()
{
  int ans = 0;
  rep(i,0,1000)
  {
    string rn;
    cin >> rn;
    string bestRn = d2r(r2d(rn));
    ans += sz(rn)-sz(bestRn);
  }
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