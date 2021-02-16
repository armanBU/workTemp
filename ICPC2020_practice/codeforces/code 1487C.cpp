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
ll ar_wi[110],ar_lo[110],ar_de[110];
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
        vector<pair<PR,ll>>V;
        ll n;
        cin>>n;
        if(n%2==0)
        {
            ll win=(n/2)-1;
            ll left=1;
            while(1)
            {
                if((ll)V.size()==(n*(n-1))/2)break;
                ll val=left+1;
                while(ar_wi[left]<win)
                {
                    V.PB({{left,val},1});
                    val++;
                    ar_wi[left]++;
                }
                while(ar_lo[left]<win)
                {
                    V.PB({{left,val},-1});
                    val++;
                    ar_lo[left]++;
                }
                V.PB({{left,val},0});
                //cout<<left<<" "<<val<<" xx\n";
                if((ll)V.size()==(n*(n-1))/2)break;
                ll right=val-1;
                while(val<=n&&ar_wi[val]<win)
                {
                    V.PB({{right,val},1});
                    right--;
                    ar_wi[val]++;
                }
                while(val<=n&&ar_lo[val]<win)
                {
                    V.PB({{right,val},-1});
                    right--;
                    ar_lo[val]++;
                }
            }
            VST(V);
            ll tm=(n*(n-1))/2;
            for(ll i=0; i<tm; i++)
            {
                cout<<V[i].ff.ff<<" "<<V[i].ff.ss<<" "<<V[i].ss<<" \n";
            }
            cout<<"\n";
        }

        else
        {
            ll win=(n/2);
            ll left=1;
            while(1)
            {
                if((ll)V.size()==(n*(n-1))/2)break;
                ll val=left+1;
                while(ar_wi[left]<win)
                {
                    V.PB({{left,val},1});
                    val++;
                    ar_wi[left]++;
                }
                while(ar_lo[left]<win)
                {
                    V.PB({{left,val},-1});
                    val++;
                    ar_lo[left]++;
                }
                // V.PB({{left,val},0});
                if((ll)V.size()==(n*(n-1))/2)break;
                ll right=val-1;
                while(val<=n&&ar_wi[val]<win)
                {
                    V.PB({{right,val},1});
                    right--;
                    ar_wi[val]++;
                }
                while(val<=n&&ar_lo[val]<win)
                {
                    V.PB({{right,val},-1});
                    right--;
                    ar_lo[val]++;
                }
            }
            VST(V);
            ll tm=(n*(n-1))/2;
            for(ll i=0; i<tm; i++)
            {
                cout<<V[i].ff.ff<<" "<<V[i].ss<<" "<<V[i].ss<<" \n";
            }
            cout<<"\n";

        }


    }
///*****************************  ALHAMDULILLAH  *****************************/
}





