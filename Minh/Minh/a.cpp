#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fr(i,d,c) for(ll i=d;i<=c;i++)
#define fl(i,d,c) for(ll i=d;i>=c;i--)
long long n,a[1000009],s[1000009],q,t;
struct pt{
    ll sum,pf;
};
pt tree[4000009];
void cos()
{
    long long t=1;
    for(long long i=1;i<=n*2;i++)
    {
        cout<<tree[i].sum<<" ";
        if(i==pow(2,t)-1) {t++;cout<<'\n';}
    }
    cout<<'\n';
}
void copf()
{
    long long t=1;
    for(long long i=1;i<=n*2;i++)
    {
        cout<<tree[i].pf<<" ";
        if(i==pow(2,t)-1) {t++;cout<<'\n';}
    }
    cout<<'\n';
}
void build(int index,int l,int r)
{
    if(l==r)
    {
        tree[index].sum=a[l];
        tree[index].pf=a[l];
    }
    else{
    int mid=(l+r)/2;
    build(index*2,l,mid);
    build(index*2+1,mid+1,r);
    tree[index].sum=tree[index*2].sum+tree[index*2+1].sum;
    tree[index].pf=max(tree[index*2].pf,tree[index*2].sum+tree[index*2+1].pf);
    }
}
void update(int node, int l, int r, int pos , int val)
{
    if(l==r)
    {
        tree[node].sum=val;
        tree[node].pf=val;
        a[pos]=val;
    }
    else{
         int mid=(l+r)/2;
         if(l<=pos&&pos<=mid) update(node*2,l,mid,pos,val);
         else update(node*2+1,mid+1,r,pos,val);
        tree[node].sum=tree[node*2].sum+tree[node*2+1].sum;
        tree[node].pf=max(tree[node*2].pf,tree[node*2].sum+tree[node*2+1].pf);
    }
}
pt query(int index,int l,int r, int dd, int dc)
{
    pt kt,kq;
    kt.sum=0;
    kt.pf=0;
    if(dd>r||l>dc)
    {
        return kt;
    }
    if(l>=dd&&r<=dc)
    {
        return tree[index];
    }
    int mid=(l+r)/2;
    pt p1=query(index*2,l,mid,dd,dc);
    pt p2=query(index*2+1,mid+1,r,dd,dc);
    kq.sum=p1.sum+p2.sum;
    kq.pf=max(p1.pf,p1.sum+p2.pf);
    return kq;
}
int main()
{
//    freopen("a.inp","r",stdin);
//    freopen("a.out","w",stdout);
    cin>>n>>q;
    for(long long i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    build(1,1,n);
    //cos();
    t=0;
     while(q--)
    {
        int x,y,z;
        cin>>x>>y>>z;
        if(x==2) cout<<max(t,query(1,1,n,y,z).pf)<<'\n';
        else update(1,1,n,y,z);
        //cos();
    } 
}
