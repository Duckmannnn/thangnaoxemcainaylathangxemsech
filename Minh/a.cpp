#include <bits/stdc++.h>

#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
using namespace std;
    
ll n,k,a[1000009],b[1000009],c[1000009],d[1000009],e[1000009],m[1000009],d2[1000009],dd,g=1e16,kq;

void solve() {
    
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    //freopen("a.inp","r",stdin);
    //freopen("a.out","w",stdout);
    //initialize
    cin >> n >> k;
    fr(i,1,n)
    {
      cin>>a[i];
      d[i]=a[i];
    }
    fr(i,1,n)
    {
      cin>>b[i];
      c[i]=b[i];
    }
    fr(dcm,1,n)
    {
      dd=0;  
      kq=dcm-1;   
      fr(i,1,n)
      {
        if(d[i]>c[i])
        {
          dd=1;
        }
      }
      if(dd) 
      {
        fr(i,1,n)
        {
          if(d[i]<=c[i]) d[i]+=k+1;    
          else c[i]+=k+1;
        }
      }
      fr(i,1,n)    m[i]=c[i]-d[i];
      sort(m+1,m+n+1);
      fr(i,1,n)    kq+=m[i]-m[1];
      kq+=m[1];      
      g=min(g,kq);      

      kq=dcm-1;
      fr(i,1,n)    m[i]=c[i]-d2[i];
      sort(m+1,m+n+1);
      fr(i,1,n)    kq+=m[i]-m[1];
      kq+=m[1];      
      g=min(g,kq);

      e[1]=a[n];
      fr(i,1,n-1)
      {
        e[i+1]=a[i];
      }
      fr(i,1,n)
      {
        a[i]=e[i];
        d[i]=e[i];
        d2[i]=e[i];
        c[i]=b[i];
      }
    }
    cout<<g;
}