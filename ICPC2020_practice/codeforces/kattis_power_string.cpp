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
#define MP make_pair
#define ff first
#define ss second
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
# define fast ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
int main()
{
    fast;
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        string s;
        while(cin>>s)
        {
            if(s[0]=='.')
            {
                return 0;
            }
            vector<ll>V;
            ll n;

            n=s.size();
            ll sq=sqrt(n+1);
            for(ll i=1; i<=sq; i++)
            {
                if(n%i==0)
                {
                    V.PB(i);
                    if(n/i!=i)
                    {
                        V.PB(n/i);
                    }
                }
            }
            VST(V);
            ll ans=1;
            for(ll i:V)
            {
                ll tm=i;
                ll ck=1;
                for(ll j=0; j<n; j++)
                {
                    if(s[j]!=s[j%tm])
                    {
                        ck=0;
                        break;
                    }
                }
                if(ck)
                {
                    ans=n/i;
                    break;
                }
            }
            cout<<ans<<"\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


