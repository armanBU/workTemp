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
#define MAX 1000003
vector<ll>prime_list;
bool prime_ck[1000101];
void seive()
{
    prime_ck[0]=prime_ck[1]=true;
    prime_list.push_back(2);
    for(ll i=4; i<=MAX; i+=2)
    {
        prime_ck[i]=true;
    }
    for(ll i=3; i<=MAX; i+=2)
    {
        if(prime_ck[i]==0)
        {
            prime_list.push_back(i);
            for(ll j=i*i; j<=MAX; j+=(i+i))
            {
                prime_ck[j]=1;
            }
        }
    }
    //Here prime_list vector indicate list of all prime number
    //prime_ck array indicate a number is prime ? or not ?
    //if prime_ck[n]=0 then number is prime else not a prime
}
int main()
{
    seive();
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
//    freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=1;
    //sf1(tcase);
    ll n;
    while(cin>>n){
        if(n==0)break;
        vector<ll>V;
        for(ll i:prime_list){
            if(i>n)break;
            ll cnt=0;
            ll num=n;
            while(num>=i){
                num/=i;
                cnt++;
            }
            if(i==5){
                V[0]-=cnt;
                V.PB(0);
            }
            else{
                V.PB(cnt);
            }
        }
        if(n==1){
            cout<<"1\n";continue;
        }
        ll ans=pow(2,V[0]);
        ll siz=V.size();
        for(ll i=1;i<siz;i++){
            ans=((ans%10)*((ll)pow(prime_list[i],V[i])%10))%10;
        }
        cout<<ans<<"\n";
    }
    return 0;
///*****************************  ALHAMDULILLAH  *****************************/
}


