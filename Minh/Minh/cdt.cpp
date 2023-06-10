#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;
    
ll n;
const int M=1e9+7;
ll bp(ll x)
{
    return (x*x)%M;
}
ll poww(ll a, ll b)
{
   if(b==0)
   {
    return 1;
   }
   else{
    if(b%2==0) return bp(poww(a,b/2)%M);
    else return (bp(poww(a,b/2)%M)*a%M)%M;
   }
}
void solve() {
    cout<<poww(2,n);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    //initialize
    cin >> n;
    solve();
}