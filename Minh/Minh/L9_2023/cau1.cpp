#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;
    
ll n;

ll tt(ll d, ll c)
{
  return(c+d)*((c-d)/2+1)/2;
}

void solve() {
    if(n%2==0)
    {
      cout<<tt(2,n)-tt(1,n-1);
      //cout<<" "<<tt(2,n)<<" "<<tt(1,n-1);
    }
    else{
      cout<<tt(2,n-1)-tt(1,n);
      //cout<<" "<<tt(2,n-1)<<" "<<tt(1,n);
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("cau1.inp","r",stdin);
    freopen("cau1.out","w",stdout);
    //initialize
    cin >> n;
    solve();
}