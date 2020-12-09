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
const int N=5e6;
ull toten[N+10];
void totient(){
    for(ll i=1;i<=N;i++){
        toten[i]=i;
    }
    toten[1]=0;
    for(ll i=2;i<=N;i++){
        if(toten[i]==i){
            for(ll j=i;j<=N;j+=i){
                toten[j]/=i;
                toten[j]*=(i-1);
            }
        }
        toten[i]=toten[i-1]+(toten[i]*toten[i]);
    }
}
int main()
{
    totient();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
    //freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    scanf("%lld",&tcase);
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        scanf("%lld%lld",&n,&m);
        printf("Case %lld: %llu\n",test,toten[m]-toten[n-1]);
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
