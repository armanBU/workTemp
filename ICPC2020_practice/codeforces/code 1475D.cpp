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
    ll tcase=1;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m,sum=0;
        cin>>n>>m;
        vector<ll>V,one,two;
        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            V.PB(a);sum+=a;
        }

        for(ll i=0;i<n;i++){
            ll a;
            cin>>a;
            if(a==1){
                one.PB(V[i]);
            }
            else{
                two.PB(V[i]);
            }
        }
        if(sum<m){
            cout<<"-1\n";continue;
        }
        VST(one);
        VST(two);
        reverse(one.begin(),one.end());
        reverse(two.begin(),two.end());
        ll left=0;
        ll right=0;
        ll ans=0;
        ll siz1=one.size();
        ll siz2=two.size();
        sum=0;
        while(left<siz1&&right<siz2&&sum<m){
            if(sum+one[left]>=m){
                sum+=one[left];
                ans+=1;break;
            }
            if(sum+two[right]>=m){
                sum+=two[right];
                ans+=2;break;
            }
            if(left<siz1-1){
                ll tm1=one[left]+one[left+1];
                ll tm2=two[right];
                if(tm2>=tm1){
                    sum+=tm2;right++;ans+=2;
                }
                else{
                    sum+=one[left];
                    left+=1;ans+=1;
                }

            }
            else{
                if(one[left]>=two[right]){
                    sum+=one[left];
                    ans+=1;
                    left++;
                }
                else{
                    sum+=two[right];
                    ans+=2;
                    right++;
                }
            }
        }
        if(sum<m){
            while(left<siz1){
                sum+=one[left++];
                ans+=1;
                if(sum>=m)break;
            }
             while(right<siz2){
                sum+=two[right++];
                ans+=2;
                if(sum>=m)break;
            }
        }
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}
/*
3 32
29 20 10
2 1 1
ans:3

*/

