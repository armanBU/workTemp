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
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<pair<PR,ll>>V;
        ll n,C;
        cin>>n>>C;
        for(ll i=0; i<n; i++)
        {
            ll a,b,c;
            cin>>a>>b>>c;
            V.PB({{a,b},c});
        }
        VST(V);
        priority_queue< PR, vector <PR>, greater<PR> > pq;
        ll sum=0;
        sum+=V[0].second;
        pq.push({V[0].first.second,V[0].second});
        ll prev=V[0].first.first;
        ll ans=0;
        for(ll i=1; i<n; i++)
        {
            ll a=V[i].first.first;
            ll b=V[i].first.second;
            ll c=V[i].second;
            while(!pq.empty())
            {
                if(pq.top().first>=a)
                {
                    break;
                }
                PR nilam=pq.top();
                ll tm_siz=abs(prev-nilam.first)+1;
                prev=nilam.first+1;
                ans+=min(tm_siz*C,sum*tm_siz);
                sum-=pq.top().second;
                pq.pop();
                while(!pq.empty())
                {
                    if(pq.top().first==nilam.first)
                    {
                        sum-=pq.top().second;
                        pq.pop();
                    }
                    else
                    {
                        break;
                    }

                }
            }

            ll dif=abs(a-prev);
            ll mm=min(sum*dif,C*dif);
            ans+=mm;
            prev=a;
            pq.push({b,c});
            sum+=c;
        }
        while(!pq.empty())
        {
            PR nilam=pq.top();
            ll siz=pq.size();
            ll tm_siz=abs(prev-nilam.first)+1;
            ans+=min(tm_siz*C,sum*tm_siz);
            prev=nilam.first+1;
            sum-=pq.top().second;
            pq.pop();
            while(!pq.empty()&&pq.top().first==nilam.first)
            {
                sum-=pq.top().second;
                pq.pop();
            }
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
8 100000000
1 3 4
2 5 5
3 6 7
4 7 2
5 6 2
4 7 3
8 9 4
10 12 3



*/


