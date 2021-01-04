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
#define tt third
#define mod 1000000007
#define T(n) printf("test %d\n",n)
int dx[] = {0,0,1,-1,2,2,-2,-2,1,-1,1,-1};
int dy[] = {1,-1,0,0,1,-1,1,-1,2,2,-2,-2};
typedef long long int ll;
typedef unsigned long long int ull;
using namespace std;
ll mem[4010][4010],n,k;
vector<ll>V,cum;
ll dp(ll i,ll sum)
{
    //cout<<i<<" "<<sum<<" xxx\n";
    if(sum>=k)
    {
        ll retun=0;
        ll second=cum[i-1]-sum;
        if(second>=k)
        {
            retun=i;
        }
        else
        {
            ll baki=k-second;
            if(cum[n-1]-cum[i-1]>=baki)
            {
                baki+=cum[i-1];
                ll pos=lower_bound(cum.begin(),cum.end(),baki)-cum.begin();
                //pos--;
                pos++;
                retun=pos;
            }
            else
            {
                retun=LONG_MAX;
            }

        }
        //cout<<i<<" "<<retun<<" x\n";
        return retun;
    }
    else if(i>=n)
    {
        return LONG_MAX;
    }
    if(mem[i][sum]!=-1)return mem[i][sum];
    ll ans=LONG_MAX;
    ans=min(ans,dp(i+1,sum+V[i]));
    ans=min(ans,dp(i+1,sum));
    return mem[i][sum]=ans;
}
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
        V.clear();
        cum.clear();
        cin>>n>>k;
        //cout<<n<<" "<<k<<"\n";
        for(ll i=0; i<=n; i++)
        {
            for(ll j=0; j<=k; j++)
            {

                mem[i][j]=-1;

            }
        }
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
        }
        VST(V);
        reverse(V.begin(),V.end());
        vector<ll>V2;
        ll temp=0;
        ll ck=0;
        for(ll i=0;i<n;i++){
            temp+=V[i];
            V2.PB(V[i]);
            if(temp>=k){
                ck++;
                temp=0;
            }
            if(ck>1){
                break;
            }
        }
        V.clear();
        V=V2;
        ll sum=0;
        for(ll i:V)
        {
            sum+=i;
            cum.PB(sum);
        }
//        for(ll i=0;i<n;i++){
//            cout<<V[i]<<" ";
//        }
//        cout<<"\n";
//        for(ll i=0;i<n;i++){
//            cout<<cum[i]<<" ";
//        }
//        cout<<"\n";
        n=V.size();
        ll ans=dp(0,0);
        if(ans>n)
        {
            cout<<"-1\n";
        }
        else
        {
            cout<<ans<<"\n";
        }

    }
///*****************************  ALHAMDULILLAH  *****************************/
}
