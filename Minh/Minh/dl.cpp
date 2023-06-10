#include <bits/stdc++.h>
 
#define int long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
 
using namespace std;
 
int n,m,vis[100001],dis[100001],k,sl[1000009],dis2[100001],sl2[1000009];
vector<pair<int,int>> adj[100001];
priority_queue<pair<int,int>> q;
void solve() {
    for(int i = 2; i <= n; ++i) dis[i] = LLONG_MAX;
    q.push({0,1});
    sl[1]=1;
    while(!q.empty()) {
        int a = q.top().second;
        q.pop();
        if(vis[a]==false)
        {
            vis[a]=true;
        for(auto i : adj[a]) {
            int b = i.first, w = i.second;
            if(dis[a]+w == dis[b]) {
                sl[b]+=sl[a];
            }
            if(dis[a]+w < dis[b]) {
                dis[b] = dis[a]+w;
                sl[b]=sl[a];
                q.push({-dis[b],b});
            }
        }
        }
    }
/*     for(int i = 1; i <= n; ++i) cout << dis[i] << ' '; cout<<'\n';
    for(int i = 1; i <= n; ++i) cout << sl[i] << ' '; cout<<'\n'; */
        
    for(int i = 1; i <= n; ++i) dis2[i] = LLONG_MAX;
    for(int i = 1; i <= n; ++i) vis[i] = false;
    dis2[k]=0;
    q.push({0,k});
    sl2[k]=sl[k];
    while(!q.empty()) {
        int a = q.top().second;
        q.pop();
        if(vis[a]==false)
        {
            vis[a]=true;
        for(auto i : adj[a]) {
            int b = i.first, w = i.second;
            if(dis2[a]+w == dis2[b]) {
                sl2[b]+=sl2[a];
            }
            if(dis2[a]+w < dis2[b]) {
                dis2[b] = dis2[a]+w;
                sl2[b]=sl2[a];
                q.push({-dis2[b],b});
            }
        }
        }
    }
/*     for(int i = 1; i <= n; ++i) cout << dis2[i] << ' '; cout<<'\n';
    for(int i = 1; i <= n; ++i) cout << sl2[i] << ' '; cout<<'\n'; */
    if(dis2[n]+dis[k]==dis[n]){
        cout<<sl2[k];
    }
    else{
        cout<<0;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
 
    //initialize
    cin >> n >> m >>k;
    while(m--) {
        int a,b,c;
        cin >> a >> b >> c;
        adj[a].emplace_back(b,c);
        //adj[b].emplace_back(a,c);
    }
    solve();
}