#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;
    
ll n,x,y,q,t,up[200009][20],L[200009],chan[200009],d1,d2;
vector<vector<ll>>adj(200009);

void dfs(ll i){
    chan[i]++;
    for(ll j: adj[i]){
        if(j==up[i][0]) continue;
        L[j]=L[i]+1;
        up[j][0]=i;
        fr(k,1,17) up[j][k]=up[up[j][k-1]][k-1];
         dfs(j);
         chan[i]+=chan[j];
    }
}
 
 ll lca(ll u, ll v)
 {
    if(L[u]!=L[v])
    {
        if(L[u]<L[v]) swap(u,v);
        ll k=L[u]-L[v];
        for(ll j=0;(1<<j)<=k;j++)
        {
            if(k>>j&1) u=up[u][j];
        }
    }
    if(u==v) return u;
    ll k=__lg(L[u]);
    fl(j,k,0){
        if(up[u][j]!=up[v][j]) u = up[u][j], v = up[v][j];
    }
    return up[u][0];
 }

 void solve() {
    cin>>x>>y;
    ll t=lca(x,y);
    if(t==x||t==y)
    {
        if(L[x]<L[y]) swap(x,y);
        ll u=x, v=y;
            ll k=L[u]-L[v];
            if(k%2==0) k/=2;
            else {
                cout<<0<<'\n';
                return;
            }
            for(ll j=0;(1<<j)<k;j++)
            {
                if(k>>j&1) u=up[u][j];
            }
        x=u;
        u=up[u][0];
        cout<<chan[u]-chan[x]<<'\n';
        return;
    }
    if(L[x]!=L[y]) {
        cout<<0<<'\n';
        return;
    }
    else{
        cout<<n-chan[t]+1<<'\n';
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    //initialize
    cin >> n;
    fr(i,1,n-1) 
    {
        cin>>x>>y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    dfs(1);
    //fr(i,1,n) cout<<chan[i]<<" "; cout<<'\n';
    cin>>q;
     while(q--){
     solve();
     }
}