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
    //cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m;
        cin>>n;
        vector<ll>V;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        ll ans=1;
        set<ll>st;
        for(ll i=1; i<n; i++)
        {
            ll val=V[0]+V[i];
            ll sq=sqrt(val+1);
            for(ll j=1; j<=sq; j++)
            {
                if(val%j==0)
                {
                    ll rev=val/j;
                    st.insert(j);
                    st.insert(rev);
                }
            }
        }
        vector<ll>div;
        for(ll i:st)
        {
            div.PB(i);
        }
        VST(div);
        reverse(div.begin(),div.end());
        ll si_d=div.size();
        for(ll cc=0;cc<si_d;cc++)
        {
            ll i=div[cc];
            vector<ll>mo;
            for(ll j=0; j<n; j++)
            {
                ll rem=V[j]%i;
                if(rem>0)mo.PB(rem);
            }
            ll siz=mo.size();
            if(siz%2!=0)
            {
                continue;
            }
            if(siz==0){
                ans=i;break;
            }
            VST(mo);
            ll j=0,k=siz-1,ck=1;
            while(j<k)
            {
                if(mo[j]+mo[k]!=i)
                {
                    ck=0;
                    break;
                }
                j++;
                k--;
            }
            if(ck)
            {
                ans=i;
                break;
            }
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



