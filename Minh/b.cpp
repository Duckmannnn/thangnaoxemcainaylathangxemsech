#include<bits/stdc++.h>
using namespace std;
long long n,a[1000009],tree[1000009],q,lazy[1000009];
void build(int node, int l, int r)
{
    if(l==r)
    {
        tree[node]=a[l];
    }
    else
    {
         int mid=(l+r)/2;
         build(node*2,l,mid);
         build(node*2+1,mid+1,r);
         tree[node]=max(tree[node*2],tree[node*2+1]);
    }
}
void update(int node, int l, int r, int dd,int dc , int val)
{
    if(lazy[node])
    {
        tree[node]+=lazy[node];
        if(l!=r)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(dc<l||r<dd)
    {
        return ;
    }
    if(dd<=l&&r<=dc)
    {
        tree[node]+=val;
        if(l!=r)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }
        return ;
    }
         int mid=(l+r)/2;
          update(node*2,l,mid,dd,dc,val);
          update(node*2+1,mid+1,r,dd,dc,val);
         tree[node]=max(tree[node*2],tree[node*2+1]);
}
long long query(int node, int l , int r, int dd, int dc)
{
    if(lazy[node])
    {
        tree[node]+=lazy[node];
        if(l!=r)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(dc<l||r<dd)
    {
        return LLONG_MIN;
    }
    if(dd<=l&&r<=dc)
    {
        return tree[node];
    }
     int mid=(l+r)/2;
     return max(query(node*2,l,mid,dd,dc),query(node*2+1,mid+1,r,dd,dc));
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    //for(long long i=1;i<=4*n;i++ ) cout<<tree[i]<<" "; cout<<'\n';
    while(q--)
    {
        int x,y,z,o;
        cin>>x;
        if(x==0)
        {
            cin>>y>>z>>o;
            update(1,1,n,y,z,o);
        }
        else
        {
            cin>>y>>z;
            cout<<query(1,1,n,y,z)<<'\n';
        }
    }
}

