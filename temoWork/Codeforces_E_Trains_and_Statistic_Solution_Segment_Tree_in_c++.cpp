/*
    Sk arman Hossain
    University of Barisal

    Problem name : Codeforces E. Trains and Statistic
    Algorithm : Segment Tree
 */
#include<bits/stdc++.h>
#define nl printf("\n");
#define N 110001
#define PR pair<ll,ll>
#define sf1(n) scanf("%lld", &n)
#define sf2(n, m) scanf("%lld %lld",&n,&m)
#define sf3(n, m,k ) scanf("%lld %lld %lld",&n,&m,&k)
#define pfn(n) printf("%d\n",n)s
#define pf1(n) printf("%d ",n)
#define pfl1(n) printf("%lld ",n)
#define pfln(n) printf("%lld\n",n)
#define pfu(n) printf("%llu\n",n)
#define pfs(s) printf("%s",s)
#define YES printf("YES\n")
#define NO printf("NO\n")
#define minus1 printf("-1\n")
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
//ll big_mod(ll base,ll power,ll Mod){if(power==0){return 1;}else if(power%2==1){ll p1=base%Mod;ll p2=(big_mod(base,power-1,Mod))%Mod;return (p1*p2)%Mod;}else if(power%2==0){ll p1=(big_mod(base,power/2,Mod))%mod;return (p1*p1)%Mod;}}
class PAIR
{
public:
    ll first;
    ll second;
    ll third;
};
vector<ll>V,V2,V3;
ll s_tree[N*3],ar[N];
ll segmentTree(ll n,ll b,ll e)
{
    if(b==e)
    {
        s_tree[n]=ar[b];
        return ar[b];
    }
    ll l=n*2;
    ll r=n*2+1;
    ll mid=(b+e)/2;
    segmentTree(l,b,mid);
    segmentTree(r,mid+1,e);
    s_tree[n]=min(s_tree[l],s_tree[r]);
    return s_tree[n];
}
ll update(ll n,ll b,ll e,ll i,ll j,ll val)
{
    if(b>j||e<i)
    {
        return INT_MAX;
    }
    if(b>=i&&e<=j)
    {
        s_tree[n]=val;
        return val;
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    ll p=update(l,b,mid,i,j,val);
    ll q=update(r,mid+1,e,i,j,val);
    s_tree[n]=min(p,q);
    return min(p,q);
}
ll query(ll n,ll b,ll e,ll i,ll j)
{
    if(b>j||e<i)
    {
        return INT_MAX;
    }
    if(b>=i&&e<=j)
    {
        return s_tree[n];
    }
    ll l=n*2;
    ll r=(n*2) + 1;
    ll mid=(e+b)/2;
    ll p=query(l,b,mid,i,j);
    ll q=query(r,mid+1,e,i,j);
    return min(p,q);
}
int main()
{
    // fast;
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {

        ll n;
        sf1(n);
        for(ll i=0; i<=n; i++)
        {
            ar[i]=LONG_MAX;
        }
        ll bulid=segmentTree(1,1,n);
        for(ll i=0; i<n-1; i++)
        {
            ll a;
            sf1(a);
            V.PB(a);
        }
        ll ans=1,node=n-2;
        ll up=update(1,1,n,node+1,node+1,1);
        for(ll i=n-3; i>=0; i--)
        {
            ll tm=V[i]-node;
            ll tm_ans=tm;
            tm_ans+=n-V[i];
            ll que=0;
            if(n-V[i]>0)
            {

                que=query(1,1,n,node+1,V[i]);
            }
            tm_ans+=que;
            up=update(1,1,n,node,node,tm_ans);
            ans+=tm_ans;
            //printf("%lld %lld \n",node,ans);
            node--;
        }
        printf("%lld\n",ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
