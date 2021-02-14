/*
    Sk arman Hossain
    University of Barisal
    Problem name :
    Algorithm :
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
#define N 200100
vector<ll>edj[N];
bool color[N];
ll cum[N];
ll cum_fav[N];
bitset<200010>fav;
vector<PR>V;
class stuc
{
public:
    ll non_fav;
    ll fav;
    ll node;
};
bool operator<(const stuc& p1, const stuc& p2)
{
    if(p1.non_fav!=p2.non_fav)
    {
        return p1.non_fav<p2.non_fav;
    }
    if(p1.fav!=p2.fav)
    {
        return p1.fav>p2.fav;
    }
    return p1.node<p2.node;
}
PR dfs(ll node)
{
    color[node]=false;
    ll siz=edj[node].size();
    ll mi=9999999999;
    ll fa=0;
    for(ll i=0; i<siz; i++)
    {
        ll tm=edj[node][i];
        if(color[tm]==true)
        {
            color[tm]=false;
            PR t=dfs(tm);
            mi=min(mi,t.first);
            fa+=t.second;

        }
    }
    if(fav[node]==1)
    {
        if(mi>999999)mi=0;
        cum[node]=mi+1;
        if(mi>0)
        {
            cum_fav[node]=fa;
        }
    }
    else
    {

        cum[node]=0;
        if(mi==0||mi>9999999)
        {
            cum_fav[node]=1;
        }
        else
        {
            cum_fav[node]=fa+1;
        }
    }
    return {cum[node],cum_fav[node]};
}
void bfs(ll node)
{
    priority_queue<stuc>pq;
    stuc tt;
    tt.non_fav=cum[1];
    tt.fav=cum_fav[1];
    tt.node=1;
    pq.push(tt);
    while(!pq.empty())
    {
        stuc pa=pq.top();
        pq.pop();
        node=pa.node;
        V.PB({node,(ll)fav[node]});
        for(ll i:edj[node])
        {
            tt.non_fav=cum[i];
            tt.fav=cum_fav[i];
            tt.node=i;
            pq.push(tt);
        }
    }
}
ll ar[200010];
int main()
{
    // fast;
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("1input.txt","r",stdin);
    ///freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n;
        //sf1(n);
        cin>>n;
        for(ll i=0; i<=n; i++)
        {
            edj[i].clear();
            color[i]=true;
            ar[i]=0;
        }
        for(ll i=1; i<=n; i++)
        {
            char ch;
            cin>>ch;
            ll tm=0;
            if(ch=='N')tm=1;
            fav[i]=tm;
        }
        for(ll i=2; i<=n; i++)
        {
            ll u;
            cin>>u;
            edj[u].PB(i);
        }
        PR x=dfs(1);
        bfs(1);
        ll cnt=0;
        for(ll i=n-1; i>=0; i--)
        {
            if(V[i].second==0)cnt++;
            ar[i]=cnt;
        }
        ll ans=0;
        for(ll i=0; i<n; i++)
        {
            if(V[i].second==1)
            {
                ans+=ar[i];
            }
            cout<<V[i].first<<" "<<V[i].second<<"\n";
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
