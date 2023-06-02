#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
ll n,m,t,d,x,y,dd,k,f[1000009],a[30],cha[1000009],kq[1000009];
vector<ll>cc;
void solve()
{
    queue<int>u;
    fr(i,1,n) 
    {
      if(!kq[(a[i]%k)]) kq[(a[i]%k)]=a[i];      
      f[a[i]%k]++;
      u.push(a[i]%k);
    }
    while(!u.empty())
    {
        int x=u.front();
        //cout<<x<<"|\n";
        u.pop();
        fr(i,1,n)
        {
          t=(x*10+a[i])%k;
          if(f[t]) continue;
          f[t]=f[x]+1;
          kq[t]=a[i];        
          cha[t]=x;
          //cout<<a[i]<<" "<<t<<" "<<kq[t]<<" "<<cha[t]<<'\n';
          if(!t) return;
          u.push(t);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    //freopen("labyrinth.inp","r",stdin);
    //freopen("labyrinth.out","w",stdout);
    //freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    cin>>n>>k;
    fr(i,1,n)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);
    solve();
    dd=1;
    t=0;
    while(t||dd)
    {
      dd=0;
      //cout<<t<<" "<<kq[t]<<" "<<cha[t]<<'\n';
      cc.push_back(kq[t]);
      t=cha[t];
    }      
    reverse(cc.begin(),cc.end());
    for(ll i: cc){
      cout<<i;
    }
}