#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;
    
ll n,x,a[1000009],l,r,g,d,c,dd;

void solve() {
    l=1;
    r=1;
    multiset<ll>m;
    while(r<=n){
        m.insert(a[r]);
        d=*m.begin();
        auto cc=--m.end();
        c=*cc;
        dd++;
        //cout<<l<<" "<<r<<" "<<d<<" "<<c<<'\n';
        
        if(abs(c-d)<=x) 
        {
            g=max(g,r-l);
            r++;
        } else{
            auto t= m.lower_bound(a[l]);
            t--;
            l++;
            m.erase(t);
            r++;
        }
    }
    cout<<g+1;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("MAGICSEQ.inp","r",stdin);
    // freopen("MAGICSEQ.out","w",stdout);

    //initialize
    cin >> n >> x;
    fr(i,1,n){
        cin>>a[i];
    }
    solve();
}