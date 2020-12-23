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
unsigned dp2[1000010];
unsigned dp5[1000010];
int main()
{
    for(ll i=2;i<=1000000;i++){
        ll cnt2=0,cnt5=0;
        ll num=i;
        while(num%2==0){
            num/=2;
            cnt2++;
        }
        while(num%5==0){
            num/=5;
            cnt5++;
        }
        dp2[i]=dp2[i-1]+cnt2;
        dp5[i]=dp5[i-1]+cnt5;
    }
    //ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,r,p,q;
        scanf("%lld%lld%lld%lld",&n,&r,&p,&q);
        ll cnt2=0,cnt5=0;
        ll num=p;
        while(num%2==0){
            num/=2;
            cnt2++;
        }
        while(num%5==0){
            num/=5;
            cnt5++;
        }
        cnt2*=q;
        cnt5*=q;
        ll ans2=dp2[n]-dp2[n-r];
        ll ans5=dp5[n]-dp5[n-r];
        ans2-=dp2[r];
        ans5-=dp5[r];
        ans2+=cnt2;
        ans5+=cnt5;
        ll ans=min(ans2,ans5);
        printf("Case %lld: %lld\n",test,ans);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



