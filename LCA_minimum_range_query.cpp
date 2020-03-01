/*
    Sk arman Hossain
    University of Barisal
    Problem name : https://www.codechef.com/problems/TALCA
    Algorithm : LCA
 */
#include<bits/stdc++.h>
#define nl printf("\n");
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
typedef long long int ll;
typedef unsigned long long int ull;
ll dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
ll dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
using namespace std;
#define N 200010
vector<ll>V;
bool color[N];
ll label[N];
ll MIN[N][25];
ll sparse[N][25];
ll parent[N];
void dfs(ll node)
{
    sparse[1][0]=1;
        MIN[1][0]=V[1];
    for(ll i=2;i<=node;i++){
        sparse[i][0]=i-1;
        MIN[i][0]=V[i];
        label[i]=i-1;
    }
}
void pre_process(ll n)
{

    for(ll j=1; (1<<j)<=n; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            sparse[i][j]=sparse[sparse[i][j-1]][j-1];
            MIN[i][j]=min(MIN[i][j],MIN[sparse[i][j-1]][j-1]);
        }
    }
}
ll query(ll u,ll v)
{
    ll mi=LONG_LONG_MAX;
    if(label[u]<label[v])
        swap(u,v);
    mi=min(V[u],V[v]);
    ll lg=0;
    for(lg=0; (1<<lg)<=label[u]; lg++)
    {

    }
    lg--;
    if(label[u]!=label[v])
    {
        for(ll i=lg; i>=0; i--)
        {
            if(label[u]-(1<<i)>=label[v])
            {
                mi=min(mi,MIN[u][i]);
                u=sparse[u][i];
            }
        }
    }
    if(u==v)
    {
        return mi;
    }
}
int main()
{
    // fast;
    //freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    for(ll test=1; test<=tcase; test++)
    {
        V.clear();
        ll n;
        sf1(n);
        for(ll i=0; i<=n; i++)
        {
            label[i]=-1;
            memset(sparse[i],-1,sizeof(sparse[i]));
            for(ll j=0;j<23;j++)
            MIN[i][j]=LONG_LONG_MAX;
        }
        V.PB(LONG_LONG_MAX);
        for(ll i=0; i<n; i++)
        {
            ll u,v,w;
            sf1(u);
            V.PB(u);
        }
        label[1]=0;
        parent[1]=1;
        dfs(n);
        pre_process(n);
        ll qq;
        sf1(qq);
        for(ll i=0; i<qq; i++)
        {
            ll u,v;
            sf2(u,v);
            ll lc=query(u,v);
            printf("%lld\n",lc);
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
//6
//1 2 3 2 1 5
