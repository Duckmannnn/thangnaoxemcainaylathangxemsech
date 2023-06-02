#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;
    
ll n,dp[1000009],g,kq;

void solve() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("cau2.inp","r",stdin);
    freopen("cau2.out","w",stdout);
    //initialize
    cin >> n;
    fr(i,1,n)
    {
      dp[i]++;
      for(ll j=i*2;j<=n;j+=i)
      {
        dp[j]++;
      }
    }
    fr(i,1,n) 
    {
     // cout<<dp[i]<<" ";
      if(g<dp[i])
      {
        g=dp[i];
        kq=i;
      }
    } 
    cout<<kq;
    solve();
}