#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;
    
ll n,x,y,n1,n2,a[1000009],b[1000009],k,u,v,g=1e16,p,q,d1,d2,l1,l2;

void solve() {
    u=1;
    v=1;
    while(v<=1e6&&u<=v)
    {
      p=lower_bound(a+1,a+n1+1,u)-a;
      q=upper_bound(a+1,a+n1+1,v)-a-1;
      d1=q-p+1;
      p=lower_bound(b+1,b+n2+1,u)-a;
      q=upper_bound(b+1,b+n2+1,v)-a-1;
      d2=q-p+1;
      if(d1>=x&&d2>=y&&v-u<g)
      {
        //cout<<d1<<" "<<d2<<'\n';        
        l1=u,l2=v;
        g=min(g,v-u);
        u++;
      }
      else{
        v++;
        if(v-u>=g) break;
      }
      //cout<<u<<" "<<v<<'\n';
    }
    cout<<l1<<" "<<l2;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    freopen("cau4.inp","r",stdin);
    freopen("cau4.out","w",stdout);
    //initialize
    cin >> n >> x>> y;
    fr(i,1,n) 
    {
      cin>>k;
      if(k>0) 
      {
        n1++;
        a[n1]=k;
      }
      else{
        n2++;
        b[n2]=abs(k);
      }
    }
    // fr(i,1,n1) cout<<a[i]<<" "; cout<<'\n';
    // fr(i,1,n2) cout<<b[i]<<" "; cout<<'\n';
    solve();
}
