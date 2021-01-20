/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
#define N 200001
#define PR pair<ll,ll>
#define sf1(n) cin>>n
#define sf2(n, m) cin>>n>>m
#define sf3(n, m,k ) cin>>n>>m>>k
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES cout<<"YES\n";
#define NO cout<<"NO\n";
#define minus1 printf("-1\n");
#define PB push_back
#define PI 3.1415926536
#define VST(v) sort(v.begin(),v.end())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define fast ios_base::sync_with_stdio(0);cin.tie(0)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
struct st
{
    ll ind;
    ll val;
};
st tree[2000000];
ll ar[300010];
st build(ll n,ll b,ll e)
{
    if(b==e)
    {
        tree[n].ind=b;
        tree[n].val=ar[b];
        return tree[n];
    }
    st p=build(n*2,b,(b+e)/2);
    st q=build(n*2+1,(b+e)/2+1,e);
    st tm;
    if(p.val<q.val)
    {
        tm=p;
    }
    else if(p.val>q.val)
    {
        tm=q;
    }
    else
    {
        if(p.ind<q.ind)
        {
            tm=p;
        }
        else
        {
            tm=q;
        }
    }
    return tree[n]=tm;
}
st query(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        return tree[n];
    }
    else if(e<l||b>r)
    {
        st tt;
        tt.ind=300010;
        tt.val=999999999999;
        return tt;
    }
    st p=query(n*2,b,(b+e)/2,l,r);
    st q=query(n*2+1,(b+e)/2+1,e,l,r);
    st tm;
    if(p.val<q.val)
    {
        tm=p;
    }
    else if(p.val>q.val)
    {
        tm=q;
    }
    else
    {
        if(p.ind<q.ind)
        {
            tm=p;
        }
        else
        {
            tm=q;
        }
    }
    return tm;
}
st update(ll n,ll b,ll e,ll l,ll r)
{
    if(b>=l&&e<=r)
    {
        st tt;
        tt.ind=300010;
        tt.val=999999999999;
        return tree[n]=tt;
    }
    else if(e<l||b>r)
    {
        return tree[n];
    }
    st p=update(n*2,b,(b+e)/2,l,r);
    st q=update(n*2+1,(b+e)/2+1,e,l,r);

    st tm;
    if(p.val<q.val)
    {
        tm=p;
    }
    else if(p.val>q.val)
    {
        tm=q;
    }
    else
    {
        if(p.ind<q.ind)
        {
            tm=p;
        }
        else
        {
            tm=q;
        }
    }
    return tree[n]=tm;
}

int main()
{
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        vector<ll>V;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        for(ll i=1; i<=m; i++)
        {
            ll a;
            cin>>a;
            ar[i]=a;
        }
        st tt=build(1,1,m);
        VST(V);
        for(ll i=0;i<n;i++){
            cout<<V[i]<<" ";
        }
        cout<<"\n";
        ll ans=0;
        for(ll i=0; i<n; i++)
        {
            ll mi=ar[V[i]];
            st qu=query(1,1,m,1,V[i]);
            if(qu.val<mi)
            {
                ans+=qu.val;
                st x=update(1,1,m,qu.ind,qu.ind);
            }
            else
            {
                ans+=mi;
            }
            cout<<V[i]<<" "<<ans<<" \n";
        }
        cout<<ans<<"\n";

    }
///*****************************  ALHAMDULILLAH  *****************************/
}



