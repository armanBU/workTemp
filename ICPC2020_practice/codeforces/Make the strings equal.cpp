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
        ll n,m;
        cin>>n;
        string fir,sec;
        cin>>fir>>sec;
        ll ar_fir[30],ar_sec[30];
        memset(ar_fir,0,sizeof(ar_fir));
        memset(ar_sec,0,sizeof(ar_sec));
        for(ll i=0;i<n;i++){
            ar_fir[fir[i]-'a']++;
        }
        for(ll i=0;i<n;i++){
            ar_sec[sec[i]-'a']++;
        }
        ll ck=0,duo_ck=0;
        for(ll i=0;i<26;i++){
            if(ar_fir[i]!=ar_sec[i]){
                ck=1;break;
            }
            if(ar_fir[i]>1){
                duo_ck=1;
            }
        }
        if(ck==1){
            cout<<"NO\n";
        }
        else if(duo_ck==1||n>26){
            cout<<"YES\n";
        }
        else{
            ll cnt=0;
            for(ll i=0;i<n;i++){
                if(fir[i]!=sec[i]){
                        ll pos;
                    for(ll j=i+1;;j++){
                        if(sec[j]==fir[i]){
                            pos=j;break;
                        }
                    }
                    for(ll j=pos;j>i;j--){
                        sec[j]=sec[j-1];
                        cnt++;
                    }
                }
            }
            if(cnt%2==0){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }
        }

    }
///*****************************  ALHAMDULILLAH  *****************************/
}



