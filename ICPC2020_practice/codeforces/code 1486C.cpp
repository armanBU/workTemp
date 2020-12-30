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
    //freopen("1input.txt","r",stdin);
//    freopen("1output.txt","w",stdout);
    ll tcase=100;
    //sf1(tcase);
    cin>>tcase;
    for(ll test=1; test<=tcase; test++)
    {
        ll n,m,ans=0;
        string s;
        cin>>s;
        n=s.size();
        if(n<=1){
            cout<<"0\n";continue;
        }
        else if(n==2){
            if(s[0]==s[1]){
                cout<<"1\n";continue;
            }
        }
        //cout<<s<<"\n";
        for(ll i=2;i<n;i++){
            if(s[i]==s[i-2]){
                char ch;
                for(ll j=0;j<=25;j++){
                    char cc=j+'a';
                    if(cc!=s[i-1]&&cc!=s[i-1]){
                        if(i+2<n){
                            if(cc!=s[i+2] && cc!=s[i+1]){
                                ch=cc;break;
                            }
                        }
                        else if(i+1<n){
                            if(cc!=s[i+1]){
                                ch=cc;break;
                            }
                        }
                        else{
                            ch=cc;
                            break;
                        }
                    }
                }
                s[i]=ch;
                ans++;
            }
            if(s[i-1]==s[i-2]){
                ll ch;
                for(ll j=0;j<=25;j++){
                    ll cc=j+'a';
                    if(cc!=s[i-2]&&cc!=s[i]){
                        if(i+1<n){
                            if(s[i+1]!=cc){
                                ch=cc;
                                break;
                            }
                        }
                        else{
                            ch=cc;
                            break;
                        }
                    }
                }
                s[i-1]=ch;
                ans++;
            }
            //cout<<s<<" "<<ans<<" \n";
        }
        if(s[n-1]==s[n-2])ans++;
        cout<<ans<<"\n";
    }
///*****************************  ALHAMDULILLAH  *****************************/
}



