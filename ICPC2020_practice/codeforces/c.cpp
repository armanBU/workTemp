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
ll res,n;
vector<ll>V,an;
ll parent[3010];
bitset<2000100>color;
void dfs(ll node,ll cnt,bitset<2020>bit,ll par)
{
    //cout<<node<<" ";
    // cout<<bit<<"\n";
    if(cnt==n-1)
    {
        for(ll j=n-1; j>=0; j--)
        {
            if(bit[j]==0)
            {
                node+=V[j];
                an.PB(j);
                break;
            }
        }
        res=node;
        ll tm=res;
        while(parent[par]!=-1)
        {
            an.PB(par);
            par=parent[par];
        }
        an.PB(par);
        ll ck=0;
        for(ll j=0; j<n; j+=2)
        {
            ll x=V[an[j]];
            ll y=V[an[j+1]];
            if(x+y==res)
            {
                res=max(x,y);
            }
            else
            {
                ck=1;
                break;
            }
        }
        if(ck==0)
        {
            res=tm;
            return;
        }
        else
        {
            res=-1;
            an.clear();
        }
    }
    for(ll i=0; i<n; i++)
    {
        //cout<<color[node+V[i]]<<" x\n";
        if(color[node+V[i]]==1&&bit[i]==0)
        {
            //cout<<node+V[i]<<" \n";
            bitset<2020>bit2;
            bit2=bit;
            bit2[i]=1;
            parent[i]=par;
            ll pos=lower_bound(V.begin(),V.end(),node+V[i])-V.begin();
            bit2[pos]=1;
            parent[pos]=i;
            dfs(node+V[i],cnt+2,bit2,pos);
        }
        else if(node+V[i]>V[n-1]){
            break;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        color.reset();
        V.clear();
        an.clear();
        cin>>n;
        n*=2;
        for(ll i=0; i<n; i++)
        {
            ll a;
            cin>>a;
            V.PB(a);
            color[a]=1;
        }
        VST(V);
//        for(ll i=0;i<n;i++){
//            cout<<V[i]<<" ";
//        }
//        cout<<"\n";
        res=-1;
        bitset<2020>bit;
        bit.reset();
        for(ll i=0; i<(n/2)+1; i++)
        {
            bit.reset();
            bit[i]=1;
            parent[i]=-1;
            dfs(V[i],1,bit,i);
            if(res!=-1)
            {
                break;
            }
        }
        if(res!=-1)
        {
            cout<<"YES\n";
            cout<<res<<"\n";
            //reverse(an.begin(),an.end());
            for(ll i=0; i<n; i+=2)
            {
                cout<<V[an[i]]<<" "<<V[an[i+1]]<<"\n";
            }
        }
        else
        {
            cout<<"NO\n";
        }
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



