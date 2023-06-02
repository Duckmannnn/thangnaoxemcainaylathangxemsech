#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;

ll n,a[1000001],dd[1000001],t;

void solve() {

}

bool kt(ll x)
{
  ll y=sqrt(x);
  if(y*y==x) return true;
  else return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    //freopen("cau3.inp","r",stdin);
    //freopen("cau3.out","w",stdout);
    //initialize
    cin >> n;
    fr(i,1,n) cin>>a[i];
    fr(i,1,n)
    {
      t=sqrt(a[i]);
      if(kt[a[i]]) dd[t]++;
    }
    fr(i,1,1e6)
    {
      if(!dd[i])
      {
        cout<<i*i;
        break;
      }
    }
    solve();
}
