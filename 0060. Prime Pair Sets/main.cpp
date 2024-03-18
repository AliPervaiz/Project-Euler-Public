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
struct node
{
  vi v;
  int sum;
  // bool operator<(const node& o) const
  // {
  //   return l>o.l;
  // }
};
ll INF = numeric_limits<int>::max();
cauto MAXK = 20001;
vi primes;
set<int> g[MAXK];
ll binpower(ll base, ll e, ll mod) {
    ll result = 1;
    base %= mod;
    while (e) {
        if (e & 1)
            result = (ll)result * base % mod;
        base = (ll)base * base % mod;
        e >>= 1;
    }
    return result;
}
bool check_composite(ll n, ll a, ll d, int s) {
    ll x = binpower(a, d, n);
    if (x == 1 || x == n - 1)
        return false;
    for (int r = 1; r < s; r++) {
        x = (ll)x * x % n;
        if (x == n - 1)
            return false;
    }
    return true;
}
bool p(ll n, int iter=5) { // returns true if n is probably prime, else returns false.
    if (n < 4)
        return n == 2 || n == 3;

    int s = 0;
    ll d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        s++;
    }

    for (int i = 0; i < iter; i++) {
        int a = 2 + rand() % (n - 3);
        if (check_composite(n, a, d, s))
            return false;
    }
    return true;
}
int c(int a, int b)
{
  return p(stoll(to_string(a)+to_string(b)))&&p(stoll(to_string(b)+to_string(a)));
}
void solve()
{
  int ans = INF;
  trav(a,primes)
  {
    trav(b,g[a])
    {
      trav(c,g[b])
      {
        if(g[a].find(c)==g[a].end()) continue;
        trav(d,g[c])
        {
          if(g[a].find(d)==g[a].end()) continue;
          if(g[b].find(d)==g[b].end()) continue;
          trav(e,g[d])
          {
            if(g[a].find(e)==g[a].end()) continue;
            if(g[b].find(e)==g[b].end()) continue;
            if(g[c].find(e)==g[c].end()) continue;
            ans = min(ans,a+b+c+d+e);
          }
        }
      }
    }
  }
  cout << ans << endl;
}
void pre()
{
  //freopen("input.txt", "r", stdin);
  rep(i,2,MAXK) if(p(i)) primes.pb(i);
  trav(i,primes) trav(j,primes) if(i<j&&c(i,j)) g[i].insert(j);
}
int32_t main() 
{
  pre();
  solve();
}