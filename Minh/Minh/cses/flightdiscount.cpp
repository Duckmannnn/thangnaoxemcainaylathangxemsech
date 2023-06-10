#include <bits/stdc++.h>
 
#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
 
using namespace std;
 
ll n,m,g=1e16;
vector<ll> vis(100001),vin(100001),dis(100001),din(100001);
vector<vector<pair<ll,ll>>> adj(100001),adn(100001);
priority_queue<pair<ll,ll>> q;
void solve(vector<ll> &vis, vector<vector<pair<ll,ll>>> &adj,ll s, vector<ll> &dis) {
    for(int i = 1; i <= n; ++i) dis[i] = 1e16;
    dis[s]=0;
    q.push({0,s});
    while(!q.empty()) {
        ll a = q.top().second;
        q.pop();
        if(vis[a]==false)
        {
            vis[a]=true;
        for(auto& [b,w] : adj[a]) {
            if(dis[a]+w < dis[b]) {
                dis[b] = dis[a]+w;
                q.push({-dis[b],b});
            }
        }
        }
    }
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //initialize
    cin >> n >> m;
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b,c);
        adn[b].emplace_back(a,c);
    }
    solve(vis,adj,1,dis);
    solve(vin,adn,n,din);
    for(int a = 1; a <= n; ++a) {
        for(auto [b,w] : adj[a])
            g = min(g,dis[a]+din[b]+w/2);
    }
    cout << g;
}