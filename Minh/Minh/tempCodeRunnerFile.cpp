#include <bits/stdc++.h>

#define int long long
using namespace std;
    
int test_case,n,k,l,d,s[1000009],t[1000009],dp[2005][2005];

void solve() {
    //read
    d=0;
   cin >> n >> l >> k;
    for(int i=1;i<=n;i++) cin>>s[i];
    for(int i=1;i<=n;i++) cin>>t[i];
    s[n+1]=l;
    t[n+1]=0;
    for(int i=1;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            dp[i][j]=1e18;
        }
    }
    dp[1][0]=0;
    for(int i=1;i<=n+1;i++){
        for(int j=0;j<=i;j++){
            for(int m=0;j+m<=k&&i+m<=n;m++){
                //cout<<dp[i+m+1][j+m]<<" "<<dp[i][j]+t[i]*(s[i+m+1]-s[i])<<" "<<i<<" "<<i+m+1<<'\n';
                dp[i+m+1][j+m]=min(dp[i+m+1][j+m],dp[i][j]+t[i]*(s[i+m+1]-s[i]));
            }
        }
       // cout<<'\n';
    }
    cout<<*min_element(dp[n+1]+0,dp[n+1]+k+1);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        solve();
}