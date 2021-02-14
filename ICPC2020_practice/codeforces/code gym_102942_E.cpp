/*
    Sk arman Hossain
    University of Barisal

    Problem :
    Solution : Combinatorics (stars and bars theorem)
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
ll mem[100110][11];
ll combination(ll n,ll k)
{
    if(k>n)
    {
        return 0;
    }
    if(k==n||k==0)
    {
        return 1;
    }
    if(mem[n][k]>0)
    {
        return mem[n][k];
    }
    return mem[n][k]=((combination(n-1,k)%mod)+(combination(n-1,k-1)%mod))%mod;
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
        ll num,ans=1;
        string s;
        cin>>num;
        cin>>s;
        ll cnt=0;
        ll mi=1;
        ll ma=9;
        for(ll i=0; i<num; i++)
        {
            if(s[i]=='-')
            {
                cnt++;
            }
            else
            {
                if(cnt==0)
                {
                    mi=max(mi,(ll)(s[i]-'0'));
                }
                else
                {
                    ma=s[i]-'0';
                    if(mi>ma){
                        ans=0;cnt=0;break;
                    }
                    ll n=(ma-mi)+1;
                    ll k=n-1;
                    n+=cnt;
                    n--;
                    ll com=combination(n,k);
                    ans=((ans%mod)*(com%mod))%mod;
                }
                ma=s[i]-'0';
                mi=max(mi,ma);
                if(mi>ma){
                    ans=0;cnt=0;break;
                }
                cnt=0;
            }
        }
        ma=9;
        if(cnt)
        {
            ll n=(ma-mi)+1;
            ll k=n-1;
            n+=cnt;
            n--;
            ll com=combination(n,k);
            ans=((ans%mod)*(com%mod))%mod;
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}





