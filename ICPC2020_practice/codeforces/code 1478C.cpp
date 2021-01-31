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
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n;
        ll num=n;
        n*=2;
        vector<ll>V;
        ll ck=1;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            if(a%2!=0)ck=0;
        }
        VST(V);
        ll prev;
        set<ll>st;
        reverse(V.begin(),V.end());
        ll cnt=num-1;
        prev=V[0];
        ll pos=prev/num;
        pos/=2;
        if(V[0]%4!=0)ck=0;
        for(ll i=3; i<n&&ck; i+=2)
        {
            if(V[i]==V[i-1])
            {
                ll x=cnt*2;
                ll tm=abs(V[i]-prev);
                if(tm%x!=0)
                {
                    ck=0;
                    break;
                }
                else
                {

                    ll ne=pos-(tm/x);
                    cnt--;
                    if(ne>0&&ne<pos)
                    {
                    }
                    else
                    {
                        ck=0;
                        break;
                    }
                    pos=ne;
                }
                prev=V[i];
            }
            else
            {
                ck=0;
                break;
            }
        }
        if(V[0]!=V[1])ck=0;
        if(ck)
        {
            YES;
        }
        else
        {
            NO;
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



