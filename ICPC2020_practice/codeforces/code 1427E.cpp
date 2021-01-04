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
ll ar[200011];
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<pair<PR,ll>>V;
        ll n,m;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a,b;
            cin>>a>>b;
            V.PB({{min(a,b),max(a,b)},i+1});
        }
        VST(V);
//        for(ll i=0;i<n;i++){
//            cout<<V[i].first.first<<" "<<V[i].first.second<<" "<<V[i].second<<"\n";
//        }
        ll ind=V[0].second;
        ar[ind]=-1;
        ll x=V[0].first.first;
        ll y=V[0].first.second;
        ll j=1;
        for(ll i=1; i<n; i++)
        {
            ll tmx=V[i].first.first;
            ll tmy=V[i].first.second;
            ll tm_ind=V[i].second;
            while(V[j].first.first<tmx&&j<n)
            {
                if(V[j].first.second<y)
                {
                    x=V[j].first.first;
                    y=V[j].first.second;
                    ind=V[j].second;
                }
                j++;
            }
            if(tmx>x&&tmy>y)
            {
                ar[tm_ind]=ind;
            }
            else
            {
                ar[tm_ind]=-1;
            }
            while(V[j].first.first<tmx&&j<n)
            {
                if(V[j].first.second<y)
                {
                    x=V[j].first.first;
                    y=V[j].first.second;
                    ind=V[j].second;
                }
                j++;
            }
        }
        for(ll i=1; i<=n; i++)
        {
            cout<<ar[i]<<" ";
        }
        cout<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



