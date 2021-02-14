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
vector<PR>edj[200010];
vector<PR>ar(200010);
ll n,k;
void dijkstra (ll node)
{
    priority_queue<PR,vector<PR>,greater<PR>>pq;
    pq.push({0,node});
    ar[1].first=0;
    ar[1].second=0;
    while(!pq.empty())
    {
        PR pa=pq.top();
        pq.pop();
        node=pa.second;
        for(auto i:edj[node])
        {
            ll child=i.first;
            ll wei=i.second;

            ll val=ar[node].first;
            val+=ar[node].second;
            val-=(ar[node].second/k);
            val+=wei;
            ll mx=max(wei,ar[node].second);
            val+=(mx/k);
            val-=mx;

            ll prev=ar[child].first;
            ll ma=ar[child].second;
            if(val<prev)
            {
                ar[child].first=val;
                ar[child].second=mx;
                if(n!=child)
                {
                    pq.push({val,child});
                }
            }
            else if(val==prev)
            {
                if(mx<ar[child].second)
                {
                    ar[child].second=mx;
                    if(n!=child)
                    {
                        pq.push({val,child});
                    }
                }

            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {

        ll m;
        cin>>n>>m>>k;
        for(ll i=0; i<=n; i++)
        {
            ar[i].first=9999999999999999;
            ar[i].second=0;
            edj[i].clear();
        }
        for(ll i=0; i<m; i++)
        {
            ll u,v,w;
            cin>>u>>v>>w;
            edj[u].PB({v,w});
            edj[v].PB({u,w});
        }

        dijkstra(1);
        //cout<<ar[n].first<<" x\n";
        ll ans=ar[n].first;
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


