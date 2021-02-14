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
vector<pair<PR,ll>>ans(200010);
vector<PR>edj[200010];
void dijkstra(ll node){
    priority_queue<pair<PR,PR>,vector<pair<PR,PR>>,greater<pair<PR,PR>>>pq;
    pq.push({{0,node},{99999999,0}});
    while(!pq.empty()){
        pair<PR,PR>parent=pq.top();
        pq.pop();
        ll cost=parent.ff.ff;
        node=parent.ff.ss;
        ll mi=parent.ss.ff;
        ll ma=parent.ss.ss;
        for(auto i:edj[node]){
            ll child=i.ff;
            ll wet=i.ss;
            ll tm_mi=min(mi,wet);
            ll tm_ma=max(ma,wet);
            ll child_cost=ans[child].ff.ff;
            child_cost+=ans[child].ff.ss;
            child_cost-=ans[child].ss;
            ll new_cost=(cost+tm_mi+wet)-tm_ma;
            if(new_cost<=child_cost){
                if(new_cost<child_cost){
                    pq.push({{cost+wet,child},{tm_mi,tm_ma}});
                    ans[child].first.first=cost+wet;
                    ans[child].first.second=tm_mi;
                    ans[child].second=tm_ma;
                }
                else{
                    ll ab_new=abs(tm_mi-tm_ma);
                    ll ab_old=abs(ans[child].first.second-ans[child].second);
                    if(ab_new>ab_old){
                        pq.push({{cost+wet,child},{tm_mi,tm_ma}});
                        ans[child].first.first=cost+wet;
                        ans[child].first.second=tm_mi;
                        ans[child].second=tm_ma;
                    }
                }
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        for(ll i=0;i<=n;i++){
            edj[i].clear();
            ans[i].ff.ff=999999999999;
            ans[i].ff.ss=0;
            ans[i].second=0;
        }
        for(ll i=0;i<m;i++){
            ll a,b,w;
            cin>>a>>b>>w;
            edj[a].PB({b,w});
            edj[b].PB({a,w});
        }
        dijkstra(1);
        for(ll j=2;j<=n;j++){
            cout<<((ans[j].ff.ff+ans[j].ff.ss)-ans[j].ss)<<" ";
        }
        cout<<"\n";
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}



