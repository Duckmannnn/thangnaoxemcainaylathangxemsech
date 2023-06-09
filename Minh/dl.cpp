#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;
    
ll n,x,y,q,t,dt,up[200009][20],l[200009],chan[200009],d1,d2;
vector<vector<ll>>adj(200009);

void dfs(ll i){
    chan[i]++;
    for(ll j: adj[i]){
        if(j==up[i][0]) continue;
        l[j]=l[i]+1;
        up[j][0]=i;
        fr(k,1,17) up[j][k]=up[up[j][k-1]][k-1];
         dfs(j);
         chan[i]+=chan[j];
    }
}
 
 ll lca(ll u, ll v)
 {
    if(l[u]!=l[v])
    {
        if(l[u]<l[v]) swap(u,v);
        ll k=l[u]-l[v];
        for(ll j=0;(1<<j)<=k;j++)
        {
            if(k>>j&1) u=up[u][j];
        }
    }
    if(u==v) return u;
    ll k=__lg(l[u]);
    fl(j,k,0){
        if(up[u][j]!=up[v][j]) u = up[u][j], v = up[v][j];
    }
    return up[u][0];
 }

ll gan(ll u, ll k)
{
    for(ll j=0;(1<<j)<=k;j++)
    {
        if(k>>j&1) u=up[u][j];
    }
    return u;
}

void no(){
    cout<<0<<'\n';
}

void solve()
{
    cin>>x>>y;
    if(x==y) {
        cout<<n<<'\n';
        return;
    }
    if(l[x]<l[y]) swap(x,y);
    t=lca(x,y);
    if(t==y) {
        if((l[x]-l[y])%2==0)
        {
            dt=(l[x]-l[y])/2;
            cout<<chan[gan(x,dt)]-chan[gan(x,dt-1)]<<'\n';
            return;
        }
        else {no();return;}
    }
    if(l[x]!=l[y]){
        if((l[x]+l[y])%2==0)
        {
            dt=(l[x]+l[y]-2*l[t])/2;
            //cout<<x<<" "<<dt<<'\n';
            cout<<chan[gan(x,dt)]-chan[gan(x,dt-1)]<<'\n';
            return;
        }
        else {no();return;}
    }
    else{
        dt=l[x]-l[t]-1;
        //cout<<x<<" "<<y<<" "<<dt<<'\n';
        cout<<n-chan[gan(x,dt)]-chan[gan(y,dt)]<<'\n';
        return;
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