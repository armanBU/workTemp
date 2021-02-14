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
int main()
{
    fast;
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<ll>V;
        ll x,y;
        cin>>x>>y;
        ll ans=0;
        if(y>=x-1)
        {
            ll sq=sqrt(x+1),ma=x;
            ans=(sq*(sq-1))/2;
            for(ll i=2; i<=sq; i++)
            {
                if(x/i<i)break;
                if(i==sq)
                {
                    ll tm=(ma-(x/i))-(x/i==i);
                    tm*=(i-1);
                    ans+=tm;
                    ma=(x/i);
                    if(i!=x/i)
                    {
                        ma-=1;
                        tm=(ma-i);
                        tm*=(i-1);
                        ans+=tm;
                    }
                }
                else
                {
                    ll tm=ma-(x/i);
                    tm*=(i-1);
                    ans+=tm;
                    ma=(x/i);
                }
            }
            if(sq<2)
            {
                ans=max(0LL,x-2);
            }
            cout<<ans<<"\n";
        }
        else
        {
            ll sq=sqrt(x+1),ma=y+1,ck=1;
            if(y>sq)
            {
                ans=(sq*(sq-1))/2;
            }
            else
            {
                ans=(y*(y-1))/2;
                ck=0;
            }
            for(ll i=2; i<=sq&&ck; i++)
            {
                if(x/i<i)break;
                if(i==sq)
                {
                    ll tm;
                    if(x/i<ma)
                    {
                        tm=(ma-(x/i))-(x/i==i);
                        tm*=(i-1);
                        ans+=tm;
                        ma=(x/i);
                    }
                    if(x/i!=i&&i<ma)
                    {
                        ma-=1;
                        tm=(ma-i);
                        tm*=(i-1);
                        ans+=tm;
                    }
                }
                else
                {
                    if(x/i<ma)
                    {
                        ll tm=ma-(x/i);
                        tm*=(i-1);
                        ans+=tm;
                        ma=(x/i);
                    }
                }
            }
            cout<<ans<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}





