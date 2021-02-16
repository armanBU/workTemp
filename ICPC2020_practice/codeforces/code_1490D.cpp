/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution :
 */
#include<bits/stdc++.h>
#define nl cout<<"\n";
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
#define VSTr(v) sort(v.begin(),v.end(),greater<long long int>())
#define VSTcmp(v,cmp) sort(v.begin(),v.end(),cmp)
#define fori(i,n) for(;i<n;i++)
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define N 200001
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll label[110],n;
vector<ll>V;
void dfs(ll dep,ll l,ll r)
{
    if(r<0)return;
    if(l>=n)return;
    if(l==r)
    {
        if(label[V[l]]==-1)
        label[V[l]]=dep;
        return;
    }
    else if(l>=0&&r<n&&r>l)
    {
        ll ma=V[l],pos=l;
        for(ll i=l; i<=r; i++)
        {
            if(V[i]>ma)
            {
                ma=V[i];
                pos=i;
            }
        }
        if(label[V[pos]]==-1){
            label[V[pos]]=dep;
            dfs(dep+1,l,pos-1);
            dfs(dep+1,pos+1,r);
        }
    }

    // T(1);
}
int main()
{

    fast;
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        cin>>n;
        V.clear();
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            label[i+1]=-1;
        }
        dfs(0,0,n-1);
        for(ll i=0; i<n; i++)
        {
            cout<<label[V[i]]<<" ";
        }
        cout<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}





