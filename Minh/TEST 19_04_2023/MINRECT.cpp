#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;
    
ll xa,xb,ya,yb,x,y;

void solve() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //freopen("MINRECT.inp","r",stdin);
    //freopen("MINRECT.out","w",stdout);
    //initialize
    cin >> xa >> ya >> xb >> yb;
    x=abs(xb-xa); y=abs(yb-ya);
    cout<<x*y;
    solve();
}