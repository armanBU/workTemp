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
ll boy[200010],girl[200010];
ll boy_pore[200010],girl_pore[200010];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
   // freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll b,g,k;
        cin>>b>>g>>k;
        for(ll i=0;i<=b;i++){
            boy[i]=0;
            boy_pore[i]=0;
        }
        for(ll i=0;i<=g;i++){
            girl[i]=0;
            girl_pore[i]=0;
        }
        vector<ll>V,V2;
        for(ll i=0;i<k;i++){
            ll a,b;
            cin>>a;
            boy[a]++;
            V.PB(a);
        }
        for(ll i=0;i<k;i++){
            ll a,b;
            cin>>a;
            girl[a]++;
            V2.PB(a);
        }
        ll ans=0;
        for(ll i=0;i<k;i++){
            ll tm=k;
            tm-=boy[V[i]];
            tm-=girl[V2[i]];
            tm+=1;
            ans+=(tm);
            //cout<<i<<" "<<ans<<"\n";
            ll num=i;
            num-=(boy_pore[V[i]]+girl_pore[V2[i]]);
            ans-=num;

            boy_pore[V[i]]++;
            girl_pore[V2[i]]++;
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


