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

vector<string> words;
vector<ll> g[20];
map<char,int> aMap;

int anagram(string a, string b)
{
  if(sz(a)!=sz(b)||a==b) return 0;
  vi f(26);
  rep(i,0,sz(a)) f[a[i]-'A']++;
  rep(i,0,sz(b)) f[b[i]-'A']--;
  trav(i,f) if(i) return 0;
  return 1;
}
int align(string a, int square)
{
  string s = to_string(square);
  aMap.clear();
  vi used(10);
  rep(i,0,sz(a))
  {
    if(aMap.find(a[i])!=aMap.end()&&aMap[a[i]]!=s[i]-'0') return 0;
    if(aMap.find(a[i])==aMap.end()&&used[s[i]-'0']) return 0;
    aMap[a[i]] = s[i]-'0';
    used[s[i]-'0'] = 1;
  }
  return 1;
}
int isSquare(ll n)
{
  ll d = round(sqrt(n));
  return d*d==n;
}
ll f(string a, string b)
{
  if(!anagram(a,b)) return 0;
  trav(square,g[sz(a)])
  {
    if(!align(a,square)) continue;
    string c = "";
    rep(i,0,sz(b)) c += to_string(aMap[b[i]]);
    ll square2 = stoll(c);
    if(sz(to_string(square))!=sz((to_string(square2)))) continue;
    if(isSquare(square2)) return max(square,square2);
  }
  return 0;
}
void solve()
{
  ll ans = 0;
  rep(i,0,sz(words)) rep(j,i+1,sz(words)) ans = max(ans,f(words[i],words[j]));
  cout << ans << endl;
}
void pre()
{
  freopen("input.txt", "r", stdin);
  string s;
  cin >> s;
  string curr;
  rep(i,0,sz(s))
  {
    if(s[i]=='"') continue;
    if(s[i]==',')
    {
      words.pb(curr);
      curr = "";
    }
    else curr += s[i];
  }
  string best = "";
  trav(s,words) if(sz(s)>sz(best)) best = s;
  repn(i,10000000,0)
  {
    ll square = (ll)i*i;
    g[sz(to_string(square))].pb((ll)i*i);
  }
}
int32_t main() 
{
  pre();
  solve();
}