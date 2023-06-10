#include <bits/stdc++.h>
 
#define int long long
using namespace std;
    
int n,m,dis[2501],dp[2501],dem,t,k,dd[2501],kt;
bool vis[2501],red[2501],no_cycle = true;
vector<int>dx;
vector<tuple<int,int,int>> edge;
vector<pair<int,int>> adj[2501];
void xuat(int x)
{
  while(dem>=0)
  {
    dd[x]++;
    dem++;
    dx.push_back(x);
    if(dd[x]==2)
    {
        break;
    }
    x=dp[x];
  }
  dem=0;
  reverse(dx.begin(),dx.end());
  for(int i=0;i<dx.size();i++) 
  {
    if(dx[i]==x) dem++;
    if(dem==1) cout<<dx[i]<<" ";
  } 
  cout<<x;
}
void solve() {
    for(int i = 1; i <= n; ++i) dis[i] = 1e14;
    dis[1] = 0;
    for(int i = 1; i <= n; ++i) {
        for(const auto& [a,b,w] : edge) {
            if(dis[b] > dis[a]+w)
            {
                dis[b] =dis[a]+w;
                dp[b]=a;
                if(i==n)t=b;
            }
        }
    }
    //for(int i=1;i<=n;i++)    cout<<dis[i]<<" "; cout<<'\n';
    if(t!=0){
        cout<<"YES\n";
        xuat(t); 
        return;
     }
    cout<<"NO";
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
    }
    solve();
}