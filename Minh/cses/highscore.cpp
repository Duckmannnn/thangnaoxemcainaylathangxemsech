#include <bits/stdc++.h>
 
#define int long long
using namespace std;
    
int n,m,dis[2501];
bool vis[2501],red[2501],no_cycle = true;
vector<tuple<int,int,int>> edge;
vector<pair<int,int>> adj[2501];
void dfs(int i) {
    if(red[i]) no_cycle = false;
    if(vis[i]) return;
    vis[i] = true;
    for(auto u : adj[i]) dfs(u.first);
}
void solve() {
    for(int i = 1; i <= n; ++i) dis[i] = -1e14;
    dis[1] = 0;
    for(int i = 1; i < n; ++i) {
        for(auto e : edge) {
            int a,b,w;
            tie(a,b,w) = e;
            if(dis[a] != -1e14)
                dis[b] = max(dis[b],dis[a]+w);
        }
    }
    for(auto e : edge) {
        int a,b,w;
        tie(a,b,w) = e;
        if(dis[b] < dis[a]+w && dis[a] != -1e14) {
            red[b] = true;
            dis[b] = dis[a]+w;
        }
    }
    dfs(n);
    if(!no_cycle) cout << -1;
    else cout << dis[n];
}
 
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //initialize
    cin >> n >> m;
    while(m--) {
        int a,b,w;
        cin >> a >> b >> w;
        edge.push_back({a,b,w});
        adj[b].push_back({a,w});
    }
    solve();
}