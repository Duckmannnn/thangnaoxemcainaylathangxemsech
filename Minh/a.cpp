#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;
    
ll n,k,dl,dp[1009][5009],kt[1009][5009];
string s;
void solve() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    //initialize
    cin >> n >> k;
    cin>>s;
    dp[0][k]=1;
    fr(i,1,n){
        if(s[i-1]=='?'){

            if(i==n){
                fr(j,0,k*2){
                    dp[i][j]=dp[i-1][j+1]+dp[i-1][j]+dp[i-1][j-1];
                    if(dp[i-1][j+1]) 
                    {
                        dp[i][j]=dp[i-1][j+1]
                    }
                }
            }
            else {
                fr(j,1,2*k-1){
                    dp[i][j]=dp[i-1][j+1]+dp[i-1][j]+dp[i-1][j-1];
                }
            }

        }
        else{

            if(i==n){
                fr(j,0,k*2){
                    if(s[i-1]=='D') dp[i][j]=dp[i-1][j];
                    if(s[i-1]=='L') dp[i][j]=dp[i-1][j+1];
                    if(s[i-1]=='W') dp[i][j]=dp[i-1][j-1];
                }
            }
            else {
                fr(j,1,2*k-1){
                    if(s[i-1]=='D') dp[i][j]=dp[i-1][j];
                    if(s[i-1]=='L') dp[i][j]=dp[i-1][j+1];
                    if(s[i-1]=='W') dp[i][j]=dp[i-1][j-1];
                }
            }

        }
    }
    cout<<dp[n][2*k]<<" "<<dp[n][0]<<'\n';
}
