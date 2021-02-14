
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
ll ar1[502][502];
ll ar2[502][502];
int main()
{
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n>>m;
        string s[502];

        for(ll i=0; i<n; i++)
        {
            cin>>s[i];
        }
        //T(1);
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=m; j++)
            {
                ar1[i][j]=ar2[i][j]=0;
            }
        }
//
        for(ll i=0; i<n; i++)
        {
            ll prev=0;
            for(ll j=0; j<m; j++)
            {
                if(s[i][j]=='*')
                {
                    prev+=1;
                }
                else
                {
                    prev=0;
                }
                ar1[i][j]=prev;
            }
        }
        for(ll i=0; i<n; i++)
        {
            ll prev=0;
            for(ll j=m-1; j>=0; j--)
            {
                if(s[i][j]=='*')
                {
                    prev+=1;
                }
                else
                {
                    prev=0;
                }
                ar2[i][j]=prev;
            }
        }
        ll ans=0;
        for(ll i=0; i<n; i++)
        {
            for(ll j=0; j<m; j++)
            {
                if(ar1[i][j]>0)
                {
                    ans++;
                    ll ma=min(ar1[i][j],ar2[i][j]);
                    for(ll k=1;; k++)
                    {
                        if(i-k<0||j-k<0||j+k>=m)
                        {
                            break;
                        }
                        ll tm=min(ar1[i-k][j],ar2[i-k][j]);
                        ma=min(ma-1,tm);
//                        if(i==2&&j==2){
//                            cout<<i<<" "<<j<<" "<<k<<" t1\n";
//                        }
                        if(ma==0)
                        {
                            //cout<<k-1<<" t0\n";
                            ans+=k-1;
                            break;
                        }
                        else if(ma==1)
                        {
                            //cout<<i<<" "<<j<<" "<<k<<" t1\n";
                            ans+=k;
                            break;
                        }
                        if(i-(k+1)<0||(j-k+1)<0||(j+k+1)>=m)
                        {
                            ans+=k;
                            break;
                        }
                    }
                }
            }
        }

        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



