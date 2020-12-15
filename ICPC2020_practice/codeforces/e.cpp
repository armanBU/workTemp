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
ll ar[200100];
ll nc2(ll n)
{
    if(n<2)
    {
        return 0;
    }
    ll dif=n-2;
    ll ans=1;
    for(ll i=dif+1; i<=n; i++)
    {
        ans*=i;
    }
    ans/=2;
    return ans;
}
ll nc3(ll n)
{
    if(n<3)
    {
        return 0;
    }
    ll dif=n-3;
    ll ans=1;
    for(ll i=dif+1; i<=n; i++)
    {
        ans*=i;
    }
    ans/=6;
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<ll>V,V2;
        ll n,m;
        cin>>n;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            ar[i]=0;
        }
        VST(V);
        for(ll i=0; i<n; i++)
        {
            ll val=V[i];
            ll cnt=1,j;
            for(j=i+1; j<n; j++)
            {
                if(V[j]!=val)
                {
                    break;
                }
                cnt++;
            }
            V2.PB(val);
            ar[(ll)V2.size()-1]=cnt;
            i=j-1;
        }
        ll siz=V2.size();
        ll ans=0;
        for(ll i=0; i<siz; i++)
        {
            ans+=nc3(ar[i]);
            if(i+2<siz)
            {
                if(V2[i+2]-V2[i]<=2)
                {
                    ll tm=nc2(ar[i]);
                    ll tm2=nc2(ar[i+1]);
                    ll tm3=nc2(ar[i+2]);

                    ans+=(tm*ar[i+1]);
                    ans+=(tm*ar[i+2]);

                    ans+=(tm2*ar[i]);
                    ans+=(tm3*ar[i]);
                    ans+=(ar[i]*ar[i+1]*ar[i+2]);

                }
                else if(V2[i+1]-V2[i]<=2)
                {
                    ll tm=nc2(ar[i]);
                    ll tm2=nc2(ar[i+1]);

                    ans+=(tm*ar[i+1]);
                    ans+=(tm2*ar[i]);
                }
            }
            else if(i+1<siz)
            {
                if(V2[i+1]-V2[i]<=2)
                {
                    ll tm=nc2(ar[i]);
                    ll tm2=nc2(ar[i+1]);

                    ans+=(tm*ar[i+1]);
                    ans+=(tm2*ar[i]);
                }
            }
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}




