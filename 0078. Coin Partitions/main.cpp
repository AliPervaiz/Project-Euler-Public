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

// https://en.wikipedia.org/wiki/Partition_function_(number_theory)
void solve()
{
  vi dp;
  dp.pb(1);
  while(dp[sz(dp)-1]!=0)
  {
    int n = sz(dp);
    int sum = 0;
    int k = 1;
    while(n-k*(3*k-1)/2>=0)
    {
      sum += pow(-1,k+1) * dp[n-k*(3*k-1)/2];
      sum = tmod(sum,1000000);
      k++;
    }
    k = -1;
    while(n-k*(3*k-1)/2>=0)
    {
      sum += pow(-1,k+1) * dp[n-k*(3*k-1)/2];
      sum = tmod(sum,1000000);
      k--;
    }
    dp.pb(sum);
  }
  cout << sz(dp)-1 << endl;
}
void pre()
{
}
int32_t main() 
{
  pre();
  solve();
}