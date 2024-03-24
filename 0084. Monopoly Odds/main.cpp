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

struct square
{
  int in;
  int t;
  bool operator<(const square& o) const
  {
    return t<o.t;
  }
};
int cc[] = {0,10,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
int ch[] = {0,10,11,24,39,5,-2,-2,-3,-4,-1,-1,-1,-1,-1,-1};
cauto n = 40;
int d[n];
cauto maxg = 1000;
cauto maxt = 10000;
int in = 0;
int doubles = 0;
int roll()
{
  return rand()%4+1;
}
void play()
{
  d[in]++;
  int r1 = roll();
  int r2 = roll();
  if(r1==r2)
  {
    if(doubles==2)
    {
      in = 10;
      doubles = 0;
      return;
    }
    doubles++;
  }
  else doubles = 0;
  in = (in+r1+r2)%n;
  if(in==2||in==17||in==33)
  {
    int act = cc[rand()%sz(cc)];
    if(act!=-1) in = act;
    return;
  }
  if(in==7||in==22||in==36)
  {
    int act = ch[rand()%sz(ch)];
    if(act==-2)
    {
      if(in%10<5) in = in/10*10+5;
      else in = (in+5)/10*10+5;
    }
    else if(act==-3)
    {
      if(in>=28) in = 12;
      else if(in>=12) in = 28;
      else in = 12;
    }
    else if(act==-4) in -= 3;
    else if(act!=-1) in = act;
    return;
  }
  if(in==30) in = 10;
}
void solve()
{
  rep(g,0,maxg)
  {
    int i = sz(cc)-1;
    while(i>0)
    {
      int j = rand()%(i+1);
      int t = cc[i];
      cc[i] = cc[j];
      cc[j] = t;
      i--;
    }
    i = sz(ch)-1;
    while(i>0)
    {
      int j = rand()%(i+1);
      int t = ch[i];
      ch[i] = ch[j];
      ch[j] = t;
      i--;
    }
    in = 0;
    doubles = 0;
    rep(t,0,maxt) play();
  }
  vector<square> squares;
  rep(i,0,n) squares.pb(square{i,d[i]});
  sort(all(squares));
  rep(i,0,3) cout << squares[n-i-1].in;
  cout << endl;
}
void pre()
{
  srand(time(NULL));
}
int32_t main() 
{
  pre();
  solve();
}