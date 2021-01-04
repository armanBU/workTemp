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
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<ll>john,jack;
        ll n,m,sjohn=0,sjack=0;
        cin>>n>>m;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            sjohn+=a;
            john.PB(a);
        }
        for(ll i=0;i<m;i++){
            ll a;
            cin>>a;
            jack.PB(a);
            sjack+=a;
        }
        if(sjohn>sjack){
            cout<<"0\n";continue;
        }
        VST(john);
        VST(jack);
        ll j=m-1;
        ll cnt=0;
        for(ll i=0;i<n;i++){
            if(jack[j]>john[i]){
                ll tmjohn=john[i];
                ll tmjack=jack[j];
                swap(john[i],jack[j]);
                sjohn-=tmjohn;
                sjohn+=john[i];
                sjack-=tmjack;
                sjack+=jack[j];
                j--;
                cnt++;
            }
            else{
                break;
            }
            if(j<0||sjohn>sjack){
                break;
            }
        }
        if(sjack<sjohn){
            cout<<cnt<<"\n";
        }
        else{
            cout<<"-1\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}


