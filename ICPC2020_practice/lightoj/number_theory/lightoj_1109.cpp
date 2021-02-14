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
bitset<34>ck;
vector<ll>prime;
vector<PR>ans;
void seive()
{
    prime.PB(2);
    for(ll i=3; i<=33; i+=2)
    {
        if(!ck[i])
        {
            prime.PB(i);
            for(ll j=i*i; j<=33; j+=(i+i))
            {
                ck[j]=1;
            }
        }
    }
    ans.PB({1,1});
    for(ll i=2; i<=1000; i++)
    {
        ll n=i;
        ll sq=sqrt(n+1);
        ll siz=prime.size();
        ll cnt=1;
        for(ll j=0; j<siz&&prime[j]<=sq; j++)
        {
            if(n%prime[j]==0)
            {
                ll cn=0;
                while(n%prime[j]==0)
                {
                    n/=prime[j];
                    cn++;
                }
                cnt*=(cn+1);
            }
            sq=sqrt(n);
        }
        if(n>1)
        {
            cnt*=2;
        }
        ans.PB({i,cnt});
    }
    sort(ans.begin(), ans.end(), [&](PR a, PR b)
    {
        if (a.second != b.second)
        {
            return a.second < b.second;
        }
        if (a.first != b.first)
        {
            return a.first > b.first;
        }
    });
//    for(ll i=0;i<10;i++){
//        cout<<ans[i].first<<" "<<ans[i].second<<" t\n";
//    }
}

int main()
{
    seive();
    ios_base::sync_with_stdio(false);cin.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n;
        cout<<"Case "<<test<<": "<<ans[n-1].first<<endl;
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



