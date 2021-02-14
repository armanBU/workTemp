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
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        vector<ll>V2,V,V_cnt;
        ll n,cnt=0;
        cin>>n;
        ll last_a=-1;
        ll last_b=-1;
        ll first_b=-1;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V2.PB(a);
        }
        for(ll i=0; i<n; i++)
        {
            ll val=V2[i],cnt=1,j=i+1;
            while(j<n)
            {
                if(V2[i]==V2[j])
                {
                    j++;
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            V.PB(val);
            V_cnt.PB(min(cnt,2LL));
            i=j-1;
        }
        ll siz=V.size();
        ll ans=0;
        ans+=V_cnt[0];
        if(siz>1)
        {
            ans+=V_cnt[1];
        }
        for(ll i=2; i<siz; i++)
        {
            if(V_cnt[i]==1)
            {
                ans+=1;
                continue;
            }
            if(V_cnt[i-1]==2){
                ans+=V_cnt[i];continue;
            }
            if(V[i-2]==V[i])
            {
                if(V_cnt[i-2]==2)
                {
                    V_cnt[i]=1;
                    ans+=1;
                }
                else
                {
                    ans+=V_cnt[i];
                }
            }
            else
            {
                ans+=V_cnt[i];
            }
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
2 2 5 7 2 2
ans:7

*/




